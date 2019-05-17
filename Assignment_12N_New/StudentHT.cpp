/*******************************************************************
Problem: Assignment 12N - StudentHT
Description: Write a program that provides for searching students by
             their id’s using hash table. The program will first input
             students one by one from a file (insert.txt) and insert
             them into hash table. Then it will input students one by
             one from a text file (search.txt) and perform searches for
             them in the hash table. It will keep a record of searches
             when required and display the summary results.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 05/16/2019

Status: 100% Complete
*******************************************************************/
#ifndef STUDENT_HT
#define STUDENT_HT

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

const string FILE_ADD_ID = "add.txt";
const string FILE_SEARCH_ID = "search.txt";

struct RecType
{
  int ID;
  string fName;
  string lName;
};

struct NodeType
{
  int ID;
  string fName;
  string lName;
  NodeType *nextItem;
};

class StudentHT
{
private:
  NodeType **hashPtr;
  int array_size;
  int numNodesSearched;
  int numIDSearched;
  bool statsEnabled;

public:
  StudentHT();
  StudentHT(const int &);
  ~StudentHT();
  void insert(const RecType &);
  RecType search(const RecType &);
  int hashing(const int &) const;
  void startStatistics();
  void endStatistics();
  void displayStatistics();
};

StudentHT::StudentHT()
{
  array_size = 0;
  hashPtr = nullptr;
  numIDSearched = 0;
  numNodesSearched = 0;
  statsEnabled = false;
}

StudentHT::StudentHT( const int &size )
{
  array_size = size;
  hashPtr = new NodeType*[array_size];

  for (int i = 0; i < array_size; hashPtr[i++] = nullptr);

  numIDSearched = 0;
  numNodesSearched = 0;
  statsEnabled = false;
}

StudentHT::~StudentHT()
{
  for (int i = 0; i < array_size; i++)
  {
    NodeType *curItem = hashPtr[i];

    while (curItem)
    {
      NodeType *temp = curItem;
      curItem = curItem->nextItem;
      delete temp;
    }
  }

  delete[] hashPtr;
}

// Rework the assignment with vectors --- More efficient way.
void StudentHT::insert(const RecType &item)
{
  int bucket = hashing(item.ID);
  NodeType *newItem = new NodeType{ item.ID, item.fName, item.lName, nullptr };

  if (!hashPtr[bucket])
  {
    hashPtr[bucket] = newItem;
  }
  else
  {
    NodeType *curItem = hashPtr[bucket];

    while (!curItem->nextItem)
    {
      curItem->nextItem = newItem;
    }
  }
}

RecType StudentHT::search(const RecType &item)
{
  int bucket = hashing(item.ID);
  NodeType *curItem = hashPtr[bucket];

  (statsEnabled) && (numIDSearched++);

  do
  {
    (statsEnabled) && (numNodesSearched++);
  } while (curItem && curItem->ID != item.ID &&
          (curItem = curItem->nextItem));

  return (curItem)
    ? RecType{ curItem->ID, curItem->fName, curItem->lName }
    : RecType{ -1 };
}

int StudentHT::hashing(const int &index) const
{
  return index % array_size;
}

void StudentHT::startStatistics()
{
  statsEnabled = true;
}

void StudentHT::endStatistics()
{
  statsEnabled = false;
}

void StudentHT::displayStatistics()
{
  cout
    << endl
    << "displayStatistics(): Statistics:"
    << endl 
    << setw(21) << " " << "Total number of ID's searched: " << numIDSearched
    << endl
    << setw(21) << " " << "Total number of nodes's searched: " << numNodesSearched
    << endl 
    << setw(21) << " " << "Number of nodes searched per ID searched: "
    << setprecision(3)
    << static_cast<double>(numNodesSearched) / numIDSearched << endl;
}

void readFile(const string &fileName, StudentHT **hshTable,
  const bool toSearch = false)
{
  int ID = 0;
  string sline = "";
  ifstream infile(fileName);

  if (infile)
  {
    getline(infile, sline);
    stringstream(sline) >> ID;

    if (!toSearch)
    {
      *hshTable = new StudentHT(ID);
    }

    getline(infile, sline);

    while (getline(infile, sline) && stringstream(sline) >> ID)
    {
      RecType temp = { ID };

      if (toSearch)
      {
        temp = (*hshTable)->search(temp);

        if (temp.ID != -1)
          cout
            << "search(): Item " << ID << " is found: "
            << endl << setw(16) << "ID #: " << temp.ID
            << endl << setw(16) << "Name: " << temp.fName << " "
            << temp.lName
            << endl << endl;
        else
          cout
            << "search(): Item " << ID << " is not found."
            << endl <<  endl ;
      }
      else
      {
        (*hshTable)->insert(temp);
        cout
          << "insert(): Item is added: "
          << endl << setw(16) << "ID #: " << temp.ID
          << endl << setw(16) << "Name: " << temp.fName << " "
          << temp.lName
          << endl << endl;
      }
    } 
  }
  else
  {
    cout
      << endl
      << "Error: The file '" << fileName << "' is not found."
      << endl  << endl;
  }
}

int main()
{
  StudentHT *hshTable = nullptr;
  string sline = "";

  cout
    << "Reading ID's from '" << FILE_ADD_ID << "' to be added..."
    << endl;

  readFile(FILE_ADD_ID, &hshTable);

  cout
    << "Reading ID's from '" << FILE_SEARCH_ID << "' to be searched..."
    << endl;

  hshTable->startStatistics();
  readFile(FILE_SEARCH_ID, &hshTable, true);
  hshTable->endStatistics();

  hshTable->displayStatistics();

  if (hshTable)
  {
    delete hshTable;
  }

  return 0;
}

#endif
