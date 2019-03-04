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
  ostream &printLog, bool isTran = false)
{
  ifstream infile(fileName);
  string sline = "";
  int index = 1;

  cout
    << "Reading from the file \"" << fileName << "\"..."
    << endl;

  if (infile)
  {
    while (getline(infile, sline))
    {
      int id = 0;
      string fName = "";
      string lName = "";
      double value = 0;

      if (sline != "")
      {
        stringstream(sline) >> id >> fName >> lName >> value;

        if (isTran)
        {
          printLog 
                 << "Update #" << index << ":" << endl
                 << sline << endl << endl;

          acc_list.update(id, fName, lName, value);

          printLog << "List after Update #" << index << ":" << endl;
          acc_list.display(printLog);
          printLog << endl;

          index++;
        }
        else
        {
          acc_list.insert(id, fName, lName, value);
        }
      }
    }

    infile.close();
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

void writeFile(AccountList &acc_list, const string &fileName)
{
  ofstream outfile(fileName);

  cout
    <<"Saving to the new master file "
    << "\"" << fileName << "\"..."
    << endl;

  if (outfile)
  {
    acc_list.display(outfile);
  }
  else
  {
    cout
      << endl
      << "Error opening the file. Please check source file name."
      << endl;
  }
}

int main()
{
  AccountList account_list;
  ofstream printLog(LOG_FILE_NAME);

  readFile(account_list, MASTER_FILE_NAME, cout);

  printLog << "List at start:" << endl;
  account_list.display(printLog);

  printLog << endl;

  readFile(account_list, TRANSACTION_FILE_NAME, printLog, true);

  printLog << "List at end:" << endl;

  account_list.display(printLog);

  printLog << endl;

  writeFile(account_list, NEW_MASTER_FILE_NAME);

  return 0;
}