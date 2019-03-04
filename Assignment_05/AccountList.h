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
  Account *previousAccount;
  Account *nextAccount;
};

class AccountList
{
  private:
    Account *list_head;
    Account *cursor;
    void erase(Account *obj);

  public: 
    AccountList();
    void insert(const int &id, const string &fName, 
                const string &lName, const double &value);
    void update(const int &id, const string &fName,
      const string &lName, const double &value);
    void display(ostream &print);

};

void AccountList::erase(Account *obj)
{
  if (obj == obj->previousAccount)
  {
    list_head = nullptr;
  }
  else
  {
    obj->nextAccount->previousAccount = obj->previousAccount;
    obj->previousAccount->nextAccount = obj->nextAccount;

    (obj == list_head) && (list_head = obj->nextAccount);
  }

  delete obj;
}

AccountList::AccountList()
{
  list_head = new Account;
  list_head->id = 0;
  list_head->fName = "";
  list_head->lName = "";
  list_head->balance = 0;
  list_head->previousAccount = list_head;
  list_head->nextAccount = list_head;

  cursor = list_head;
}

void AccountList::insert(const int &id, const string &fName,
  const string &lName, const double &amount)
{
  Account *newAcc = new Account;
  Account *curAcc;

  newAcc->id = id;
  newAcc->fName = fName;
  newAcc->lName = lName;
  newAcc->balance = amount;
  newAcc->previousAccount = nullptr; 
  newAcc->nextAccount = nullptr;

  if (!list_head)
  {
    list_head = newAcc;
    list_head->previousAccount = list_head;
    list_head->nextAccount = list_head;
  }
  else
  {
    curAcc = list_head;

    while (newAcc->id > curAcc->id)
      curAcc = curAcc->nextAccount;

    newAcc->nextAccount = curAcc;
    newAcc->previousAccount = curAcc->previousAccount;
    curAcc->previousAccount->nextAccount = newAcc;
    curAcc->previousAccount = newAcc;
  }
}

void AccountList::update(const int &id, const string &fName,
  const string &lName, const double &value)
{
  if (!cursor)
    cursor = list_head->nextAccount;

  while (id > cursor->id || id < cursor->id && cursor != list_head)
    cursor = (id > cursor->id) ? cursor->nextAccount : cursor->previousAccount;

  if (cursor->id == id)
  {
    cursor->fName = fName;
    cursor->lName = lName;
    cursor->balance += value;

    // Cheating is possible if the account created here had the 
    // negative balance at the start.
    if (cursor->balance <= 0)    
      erase(cursor);
  }
  else
  {
    insert(id, fName, lName, abs(value));
  }
}

void AccountList::display(ostream &print)
{
  for (Account *curAcc = list_head->nextAccount; curAcc != list_head;
    curAcc = curAcc->nextAccount)
    print
        << curAcc->id << " " << curAcc->fName << " " << curAcc->lName
        << curAcc->balance << endl;
}

#endif 