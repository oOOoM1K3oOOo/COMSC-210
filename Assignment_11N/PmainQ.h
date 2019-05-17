/*******************************************************************
Problem: Assignment 11N - Priority Queue (PmainQ)
Description: Stores the elements in a queue using the min heap method.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 05/05/2019

Status: 100% Complete
*******************************************************************/
#ifndef PMAINQ_H
#define PMAINQ_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/*
    Class Definition
*/

template<typename T>
class PmainQ
{
private:
  vector<T> heap_vector;
  int lastIndex;
  void maxreheapifyUpward();
  void maxreheapifyDownward();
  int findLargeChildIndex(const int &) const;
public:
  PmainQ();
  void penque(const T &);
  T pdeque();
  bool isEmpty() const;
};

/*
    Class Declaration
*/

template<typename T>
void PmainQ<T>::maxreheapifyUpward()
{
  int chIndex = lastIndex;
  int prIndex = 0;

  while (chIndex > 0 && ((prIndex = chIndex / 2) >= 0 &&
    heap_vector.at(chIndex) < heap_vector.at(prIndex)))
  {
    //swap values at child and at parent.
    swap(heap_vector.at(chIndex), heap_vector.at(prIndex));

    //Update child to parent
    chIndex = prIndex;
  }
}

template<typename T>
void PmainQ<T>::maxreheapifyDownward()
{
  int parentIndex = 0;
  int largeChildIndex = 0;

  while (parentIndex < lastIndex &&
    (largeChildIndex = findLargeChildIndex(parentIndex)) > 0 &&
    heap_vector.at(largeChildIndex) < heap_vector.at(parentIndex))
  {
    ///swap value at parentIndex with value at largeChildIndex
    swap(heap_vector.at(parentIndex), heap_vector.at(largeChildIndex));

    ///update parentIndex
    parentIndex = largeChildIndex;
  }
}

template<typename T>
int PmainQ<T>::findLargeChildIndex(const int &parentIndex) const
{
  int lChIndex = (2 * parentIndex) + 1;
  int rChIndex = (2 * parentIndex) + 2;
  int rtnIndex = -1;

  //case both children exist
  if (rChIndex <= lastIndex && lChIndex <= lastIndex)
  {
    ///compare value at rChIndex and at lChIndex
    ///return the index where the value is smaller
    rtnIndex = (heap_vector.at(rChIndex) < heap_vector.at(lChIndex)) ?
      rChIndex : lChIndex;
  }
  ///case only left child exist
  else if (lChIndex <= lastIndex)
  {
    rtnIndex = lChIndex;
  }

  return rtnIndex;
}

template<typename T>
PmainQ<T>::PmainQ()
{
  lastIndex = -1;
}

template<typename T>
void PmainQ<T>::penque(const T &elem)
{
  heap_vector.push_back(elem);
  lastIndex++;
  maxreheapifyUpward();
}

template<typename T>
T PmainQ<T>::pdeque()
{
  if (isEmpty())
    throw underflow_error("Error: No elements in the vector.");

  T temp = heap_vector.at(0);

  heap_vector.at(0) = heap_vector.at(lastIndex--);
  heap_vector.pop_back();
  maxreheapifyDownward();

  return temp;
}

template<typename T>
bool PmainQ<T>::isEmpty() const
{
  return lastIndex == -1;
}

#endif