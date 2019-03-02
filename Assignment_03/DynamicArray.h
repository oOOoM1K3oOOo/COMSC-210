/*******************************************************************
Problem: Assignment 03N - Dynamic Array Template
Question:  Convert the class that you wrote in assignment 2 to template.
            Test the template with dynamic arrays of integers and dynamic
            array of strings.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 2/10/2019

Status: 100% Complete
*******************************************************************/
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <string>

using namespace std;

template<class Type>
class DynamicArray
{
private:
  Type *dynamicArray;
  int size;

  void copyArray(const Type *arr, Type *temp, const int &length);

public:
  DynamicArray();

  DynamicArray(const DynamicArray<Type> &dsa);

  ~DynamicArray();

  int getSize() const;

  void addEntry(const Type &str);

  bool deleteEntry(const Type &str);

  Type getEntry(const int &index) const;

  DynamicArray<Type> &operator=(const DynamicArray<Type> &dsa);
};

template<class Type>
void DynamicArray<Type>::copyArray(const Type *arr, Type *temp, const int &length)
{
  for (int index = 0; index < length; index++)
  {
    *(temp + index) = *(arr + index);
  }
}

template<class Type>
DynamicArray<Type>::DynamicArray()
{
  dynamicArray = nullptr;
  size = 0;
}

template<class Type>
DynamicArray<Type>::DynamicArray(const DynamicArray<Type> &dsa)
{
  size = dsa.getSize();
  dynamicArray = new Type[size];

  copyArray(dsa.dynamicArray, dynamicArray, dsa.getSize());
}

template<class Type>
DynamicArray<Type>::~DynamicArray()
{
  delete[] dynamicArray;
}

template<class Type>
int DynamicArray<Type>::getSize() const
{
  return size;
}

template<class Type>
void DynamicArray<Type>::addEntry(const Type &str)
{
  Type *temp = new Type[getSize() + 1];

  copyArray(dynamicArray, temp, getSize());

  *(temp + getSize()) = str;

  delete[] dynamicArray;

  dynamicArray = temp;
  size++;
}

template<class Type>
bool DynamicArray<Type>::deleteEntry(const Type &str)
{
  bool retVal = false;

  if (dynamicArray != nullptr)
  {
    int index = 0;

    while (index < getSize() && getEntry(index) != str)
      index++;

    if (index < getSize())
    {
      Type *temp = new Type[getSize() - 1];

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

template<class Type>
Type DynamicArray<Type>::getEntry(const int &index) const
{
  if (dynamicArray != nullptr && (index < 0 || index >= getSize()))
    throw out_of_range("Error: Index is out of range");

  return *(dynamicArray + index);
}

template<class Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(const DynamicArray<Type> &dsa)
{
  delete[] dynamicArray;

  size = dsa.getSize();
  dynamicArray = new Type[size];

  copyArray(dsa.dynamicArray, dynamicArray, size);

  return(*this);
}

#endif