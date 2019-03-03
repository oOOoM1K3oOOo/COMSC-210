/*******************************************************************
Problem: Linked Lists Lab - Circular_double_list
Question: Write a program that can be used by a small theater to sell
    tickets for performances.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 12/1/2018

Status: 100% Complete
*******************************************************************/
#ifndef CIRCULAR_DOUBLE_LIST_H
#define CIRCULAR_DOUBLE_LIST_H

#include "Double_node.h"
#include <stdexcept>

using namespace std;

template<class Type>
class Circular_double_list
{
private:
  Double_node<Type> *list_head;
  int list_size;

  void checkRange(const int &index) const;

  void checkUnderflow() const;

  void destroy(Double_node<Type> *obj);

public:
  Circular_double_list();

  Circular_double_list(const Circular_double_list<Type> &cdl);

  ~Circular_double_list();

  int size() const;

  bool empty() const;

  Type front() const;

  Type back() const;

  Type at(int index) const;

  Double_node<Type> *head() const;

  int count(const Type &obj) const;

  void swap(Circular_double_list &list);

  void push_front(Type const &obj);

  void push_back(Type const &obj);

  Type pop_front();

  Type pop_back();

  void insertAt(int index, Type const &obj);

  void eraseAt(int index);

  // I considered using at() function, but not used it due to 
  // decrease in performance
  int find(Type const &obj);

  void clear();
};

template<class Type>
void Circular_double_list<Type>::checkRange(const int &index) const
{
  if (!empty() && (index < 0 || index >= size()))
    throw out_of_range("Error: index is out of range");
}

template<class Type>
void Circular_double_list<Type>::checkUnderflow() const
{
  if (empty())
    throw underflow_error("Error: underflow");
}

template<class Type>
void  Circular_double_list<Type>::destroy(Double_node<Type> *obj)
{
  if (obj == obj->previous())
  {
    list_head = nullptr;
  }
  else
  {
    obj->next()->previous_node = obj->previous_node;
    obj->previous()->next_node = obj->next_node;

    (obj == head()) && (list_head = obj->next());
  }

  delete obj;

  list_size--;
}

template<class Type>
Circular_double_list<Type>::Circular_double_list()
{
  list_head = nullptr;
  list_size = 0;
}

template<class Type>
Circular_double_list<Type>::Circular_double_list(const Circular_double_list<Type> &cdl) : Circular_double_list()
{
  Double_node<Type> *currNode = cdl.head();
  int currSize = cdl.size();

  while (currSize-- && currNode)
  {
    push_back(currNode->value());
    currNode = currNode->next();
  }
}

template<class Type>
Circular_double_list<Type>::~Circular_double_list()
{
  clear();
}

template<class Type>
int Circular_double_list<Type>::size() const
{
  return list_size;
}

template<class Type>
bool Circular_double_list<Type>::empty() const
{
  return !list_size;
}

template<class Type>
Type Circular_double_list<Type>::front() const
{
  checkUnderflow();

  return list_head->value();
}
 
template<class Type>
Type Circular_double_list<Type>::back() const
{
  checkUnderflow();

  return list_head->previous()->value();
}

template<class Type>
Type Circular_double_list<Type>::at(int index) const
{
  checkRange(index);

  Double_node<Type> *currentNode = head();

  while (index--)
    currentNode = currentNode->next();

  return currentNode->value();
}

template<class Type>
Double_node<Type> *Circular_double_list<Type>::*head() const
{
  return list_head;
}
 
template<class Type>
int Circular_double_list<Type>::count(const Type &obj) const
{
  int count = 0;
  Double_node<Type> *nodePtr = head();

  for (int i = size(); i > 0;
    count += (nodePtr->node_value == obj),
    nodePtr = nodePtr->next_node, i--);

  return count;
}
 
template<class Type>
void Circular_double_list<Type>::swap(Circular_double_list<Type> &list)
{
  Double_node<Type> *tempHead = list.list_head;
  int tempSize = list.list_size;

  list.list_head = list_head;
  list.list_size = list_size;

  list_head = tempHead;
  list_size = tempSize;
}

template<class Type>
void Circular_double_list<Type>::push_front(Type const &obj)
{
  insertAt(0, obj);
}
 
template<class Type>
void Circular_double_list<Type>::push_back(Type const &obj)
{
  Double_node<Type> *tempNode = list_head;

  insertAt(0, obj);

  (tempNode) && (list_head = tempNode);
}
 
template<class Type>
Type Circular_double_list<Type>::pop_front()
{
  checkUnderflow();

  Type obj = at(0);

  destroy(head());

  return obj;
}
 
template<class Type>
Type Circular_double_list<Type>::pop_back()
{
  checkUnderflow();

  Type obj = at(size() - 1);

  destroy(head()->previous());

  return obj;
}
 
template<class Type>
void Circular_double_list<Type>::insertAt(int index, Type const &obj)
{
  checkRange(index);

  Double_node<Type> *newNode = new Double_node<Type>;
  Double_node<Type> *currentNode;

  newNode->node_value = obj;

  if (!head())
  {
    list_head = newNode;
    newNode->next_node = newNode;
    newNode->previous_node = newNode;
  }
  else
  {
    currentNode = head();

    (index == 0) && (list_head = newNode);

    while (index--)
      currentNode = currentNode->next();

    newNode->next_node = currentNode;
    newNode->previous_node = currentNode->previous_node;
    currentNode->previous_node->next_node = newNode;
    currentNode->previous_node = newNode;

  }

  list_size++;
}
 
template<class Type>
void Circular_double_list<Type>::eraseAt(int index)
{
  checkRange(index);

  Double_node<Type> *currNode = head();

  while (index--)
    currNode = currNode->next();

  destroy(currNode);
}
 
template<class Type>
int Circular_double_list<Type>::find(Type const &obj)
{
  checkUnderflow();

  int count = -1;
  Double_node<Type> *currNode = head();

  while (count++ < size() && currNode->value() != obj)
    currNode = currNode->next();

  return (count >= size()) ? -1 : count;
}
 
template<class Type>
void Circular_double_list<Type>::clear()
{
  while (size() > 0)
    destroy(head());
}

#endif