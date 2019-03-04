/*******************************************************************
Problem: Assignment 05N - Account Circular Double Linked List
Question: Write a program that will update bank accounts stored in a
          master file using updates from a transaction file. The program
          will maintain accounts using a doubly linked list.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/2/2018

Status: 100% Complete
*******************************************************************/
#ifndef ACCOUNT_LIST_H
#define ACCOUNT_LIST_H

#include <string>

using namespace std;

struct Account
{
  long id;
  string fName;
  string lName;
  double balance;
  Account *accPrev;
  Account *accNext;
};

class AccountList
{
private:
  Account *list_head;
  Account *cursor;
  void erase(Account *obj);
  void insertBefore(Account *obj1, Account *obj2);
  void update(const double &balance);

public:
  AccountList();
  ~AccountList();
  void insert(const int &id, const string &fName,
    const string &lName, const double &value);
  void update(const int &id, const string &fName,
    const string &lName, const double &value);
  void display(ostream &print);
  void clear();

};

void AccountList::erase(Account *obj)
{
  if (obj == obj->accPrev)
  {
    list_head = nullptr;
  }
  else
  {
    obj->accNext->accPrev = obj->accPrev;
    obj->accPrev->accNext = obj->accNext;

    (obj == list_head) && (list_head = obj->accNext);
  }

  delete obj;
}

// Insert accNew before element accCurr
void AccountList::insertBefore(Account *accCurr, Account *accNew)
{
  accNew->accNext = accCurr;
  accNew->accPrev = accCurr->accPrev;
  accCurr->accPrev->accNext = accNew;
  accCurr->accPrev = accNew;

  (accNew->id < list_head->id) && (list_head = accNew);
}

AccountList::AccountList()
{
  list_head = nullptr;
  cursor = list_head;
}

AccountList::~AccountList()
{
  clear();
}

void AccountList::insert(const int &id, const string &fName,
  const string &lName, const double &amount)
{
  Account *accNew = new Account; 
  Account *accCurr;
  Account *tempAcc;

  accNew->id = id;
  accNew->fName = fName;
  accNew->lName = lName;
  accNew->balance = amount;
  accNew->accPrev = nullptr;
  accNew->accNext = nullptr;

  if (!list_head)
  {
    list_head = accNew;
    list_head->accPrev = list_head;
    list_head->accNext = list_head;
  }
  else
  {
    accCurr = list_head;
    
    while (accCurr->id < accNew->id && accCurr->accNext != list_head)
    {
      accCurr = accCurr->accNext;
    }

    (accNew->id > accCurr->id ) && (accCurr = accCurr->accNext);
    
    insertBefore(accCurr, accNew);
  }
}

void AccountList::update(const int &id, const string &fName,
                        const string &lName, const double &value)
{
  if( !list_head || (id < list_head->id) || 
      (id > list_head->accPrev->id))
    insert(id, fName, lName, value);
  else
  {
    if (!cursor)
      cursor = list_head;

    if (id > cursor->id)
    {
      while (id > cursor->id)
        cursor = cursor->accNext;
    }
    else if (id < cursor->id)
    {
      while (id < cursor->id)
        cursor = cursor->accPrev;
    }

    if (id == cursor->id)
      update(value);
    else
    {
      Account *accNew = new Account;
      accNew->id = id;
      accNew->fName = fName;
      accNew->lName = lName;
      accNew->balance = value;
      accNew->accPrev = nullptr;
      accNew->accNext = nullptr;

      insertBefore(((id > cursor->id) ? cursor->accNext : cursor), accNew);
    }
  }
}

void AccountList::update(const double &balance)
{
  cursor->balance += balance;

  // Cheating is possible if the account created here had the 
  // negative balance at the start.
  if (cursor->balance <= 0)
  {
    erase(cursor);

    cursor = list_head;
  }
}

void AccountList::display(ostream &print)
{
  for (Account *accCurr = list_head; (accCurr != list_head->accPrev);
    accCurr = accCurr->accNext)
    print
        << accCurr->id << " " << accCurr->fName << " " << accCurr->lName
        << " " << accCurr->balance << endl;

  print
    << list_head->accPrev->id << " " << list_head->accPrev->fName << " "
    << list_head->accPrev->lName << " " << list_head->accPrev->balance 
    << endl;
}

void AccountList::clear()
{
  while (!list_head)
    erase(list_head);
}

#endif 