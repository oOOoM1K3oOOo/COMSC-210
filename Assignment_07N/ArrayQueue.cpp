/*******************************************************************
Problem: Assignment 07N - Array Queue Definition
Question: Rewrite the code to use array instead of linked lists.
          Please do not change anything besides the data structure.
          Instead of linked list use an array. The functionality
          should remain exactly the same.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/21/2019

Status: 100% Complete
*******************************************************************/
///---------------------------------------------------------------
/// File: ArrayQueue.cpp
/// Purpose: Implementation file for a demonstration of a queue
///        implemented as an array.    
/// Data type: Character
/// Programming Language: C++
///---------------------------------------------------------------

#include "ArrayQueue.h"
#include <stdexcept>

///--------------------------------------------
/// Function: LListQueue()
/// Purpose: Class constructor.
/// Returns: void
///--------------------------------------------
ArrayQueue::ArrayQueue(const int &size)
{
  queue_capacity = size;
  queue_array = new char[queue_capacity];
  head = tail = -1;
}

///--------------------------------------------
/// Function: ~ArrayQueue()
/// Purpose: Class destructor.
/// Returns: void
///--------------------------------------------
ArrayQueue::~ArrayQueue()
{
  delete[] queue_array;     /// Deletes the allocated memory of the array
}

///--------------------------------------------
/// Function: ClearQueue()
/// Purpose: Reset the indices of head and tail.
/// Returns: void
///--------------------------------------------
void ArrayQueue::ClearQueue()
{
  head = tail = -1;     /// Reset the indices of head and tail
}


///--------------------------------------------
/// Function: Enqueue()
/// Purpose: Enqueue (add) an item into the queue.
//          Throw an overflow exception if the list
//          is full.
/// Returns: true if it was successful or false 
///          if the enqueue failed.
///--------------------------------------------
bool ArrayQueue::Enqueue(const char &ch)
{
  //if (isFull())
    //throw overflow_error("Error: overflow");
  
  /// Check overflow
  bool canEnq = false;

  /// Check if queue is not full
  if (!isFull())
  {
    /// Increment tail index
    tail++;
    /// Add item to the queue
    queue_array[tail % queue_capacity] = ch;

    canEnq = true;
  }
  
  return canEnq;
}

///--------------------------------------------
/// Function: Dequeue()
/// Purpose: Dequeue (remove) an item from the queue.
//          Throw underflow exception if the list
//          is full.
/// Returns: Deleted element if dequeue was successful
///          or null character if the dequeue failed.
///--------------------------------------------
char ArrayQueue::Dequeue()
{
  //if (isEmpty())
    //throw underflow_error("Error: underflow");
  char ch = '\0';

  /// Check if the queue is not empty
  if (!isEmpty())
  {
    /// Increment head index
    head++;
    /// Assign the deleted element to temporary variable
    ch = queue_array[head % queue_capacity];
  }

  return ch;
}

///--------------------------------------------
/// Function: isEmpty()
/// Purpose: Validate if the queue is empty.
/// Returns: true if the queue is empty; false, 
///          otherwise.
///--------------------------------------------
bool ArrayQueue::isEmpty() const
{
  return (head == tail);
}

///--------------------------------------------
/// Function: isFull()
/// Purpose: Validate if the queue is full.
/// Returns: true if the queue is full; false, 
///          otherwise.
///--------------------------------------------
bool ArrayQueue::isFull() const
{
  return ((tail - queue_capacity) == head);
}