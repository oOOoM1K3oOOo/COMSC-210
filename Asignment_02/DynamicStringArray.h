/*******************************************************************
Problem: Assignment 02N - Dynamic String Array
Question:  This project asks you to create a class called
            DynamicStringArray that includes member functions that
            allow it to emulate the behavior of a vector of strings.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 2/10/2019

Status: 100% Complete
*******************************************************************/
#ifndef DYNAMIC_STRING_ARRAY_H
#define DYNAMIC_STRING_ARRAY_H

#include <string>

using namespace std;

class DynamicStringArray
{
private:
  string *dynamicArray;
  int size;

  void copyArray(const string *arr, string *temp, const int &length)
  {
    for (int index = 0; index < length; index++)
    {
      *(temp + index) = *(arr + index);
    }
  }

public:
  DynamicStringArray()
  {
    dynamicArray = nullptr;
    size = 0;
  }

  DynamicStringArray(const DynamicStringArray &dsa)
  {
    size = dsa.getSize();
    dynamicArray = new string[size];

    copyArray(dsa.dynamicArray, dynamicArray, dsa.getSize());
  }

  ~DynamicStringArray()
  {
    delete[] dynamicArray;
  }

  int getSize() const
  {
    return size;
  }

  void addEntry(const string &str)
  {
    string *temp = new string[getSize() + 1];

    copyArray(dynamicArray, temp, getSize());

    *(temp + getSize()) = str;

    delete[] dynamicArray;

    dynamicArray = temp;
    size++;
  }

  bool deleteEntry(const string &str)
  {
    bool retVal = false;

    if (dynamicArray != nullptr)
    {
      int index = 0;

      while (index < getSize() && getEntry(index) != str)
        index++;

      if (index < getSize())
      {
        string *temp = new string[getSize() - 1];

        copyArray(dynamicArray, temp, index);
        copyArray((dynamicArray + index + 1), (temp + index), getSize() - (index + 1));

        delete[] dynamicArray;

        dynamicArray = temp;
        size--;

        (!getSize()) && (dynamicArray = nullptr);

        retVal = true;
      }
    }

    return retVal;
  }

  string getEntry(const int &index) const
  {
    if (dynamicArray != nullptr && (index < 0 || index >= getSize()))
      throw out_of_range("Error: Index is out of range");

    return *(dynamicArray + index);
  }

  DynamicStringArray &operator=(const DynamicStringArray &dsa)
  {
    delete[] dynamicArray;

    size = dsa.getSize();
    dynamicArray = new string[size];

    copyArray(dsa.dynamicArray, dynamicArray, size);

    return(*this);
  }
};

#endif