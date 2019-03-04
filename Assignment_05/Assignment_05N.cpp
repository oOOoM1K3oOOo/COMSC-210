/*******************************************************************
Problem: Assignment 05N - Main
Question: Write a program that will update bank accounts stored in a 
          master file using updates from a transaction file. The program
          will maintain accounts using a doubly linked list.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/2/2018

Status: 100% Complete
*******************************************************************/
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "AccountList.h"

using namespace std;

const string MASTER_FILE_NAME = "master.txt";
const string NEW_MASTER_FILE_NAME = "new_master.txt";
const string TRANSACTION_FILE_NAME = "tran.txt";
const string LOG_FILE_NAME = "log.txt";

void readFile(AccountList &acc_list, const string &fileName, 
              bool isTran = false)
{
  ifstream infile(fileName);
  string sline = "";

  cout 
      << "Reading from  the filefile \"" << fileName << "\"..." 
      << endl;

  if (infile)
  {
    while (getline(infile, sline))
    {
      int id = 0;

      string fName = "";
      string lName = "";
      double value = 0;

      (sline != "") && 
        (stringstream(sline) >> id >> fName >> lName >> value);

      if (isTran)
      {
        acc_list.update(id, fName, lName, value);
      }
      else
      {
        acc_list.insert(id, fName, lName, value);
      }
    }
  }
  else
  {
    cout
      << endl
      << "The file \"" << fileName << "\" is not found. " 
      << endl
      << "Please check source file name."
      << endl;
  }
}

void writeFile(const AccountList &acc_list, const string &fileName,
               bool isLog = true)
{
  ofstream outfile(fileName);

  cout
    << "Saving settings in " << ((isLog) ? "log" : "new master file")
    << "\"" << fileName << "\"..."
    << endl;


}

int main()
{
  AccountList account_list;

  cout << "List at start:" << endl;

  readFile(account_list, MASTER_FILE_NAME);

  account_list.display(cout);




  return 0;
}