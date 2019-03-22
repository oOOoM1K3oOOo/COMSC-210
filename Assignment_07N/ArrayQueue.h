/*******************************************************************
Problem: Assignment 07N - Array Queue Declaration
Question: Rewrite the code to use array instead of linked lists. 
          Please do not change anything besides the data structure. 
          Instead of linked list use an array. The functionality 
          should remain exactly the same.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/21/2019

Status: 100% Complete
*******************************************************************/
#ifndef ARRAYQUEUE_H_INCLUDED
#define ARRAYQUEUE_H_INCLUDED

///---------------------------------------------------------------
/// File: LListQueue.h
/// Purpose: Header file for a demonstration of a queue implemented
///        as a array structure.  
/// Data type: Character
/// Programming Language: C++
///---------------------------------------------------------------

class ArrayQueue
{
  private:
    char *queue_array;                   /// Char array that holds the elements
    int queue_capacity;                 /// Queue's capacity
    int head;                           /// Pointer to head of the queue
    int tail;                           /// Pointer to tail of the queue

  public:
    ArrayQueue(const int &size = 25);   /// Class constructor
    ~ArrayQueue();                      /// Class destructor
    void ClearQueue();                  /// Remove all items from the queue
    bool Enqueue(const char &);         /// Add an item in the queue
    char Dequeue();                     /// Remove an item from the queue
    bool isEmpty() const;               /// Return true if queue is empty
    bool isFull() const;                /// Return true if queue is full
};

#endif
