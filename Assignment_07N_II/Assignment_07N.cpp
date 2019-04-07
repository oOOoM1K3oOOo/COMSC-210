/*******************************************************************
Problem: Assignment 07N
Question: Rewrite the code to use array instead of linked lists.
          Please do not change anything besides the data structure.
          Instead of linked list use an array. The functionality
          should remain exactly the same.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/31/2019

Status: 100% Complete
*******************************************************************/
/**
* Queue implementation using linked list C style implementation ( no OOP).
*/

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int CAPACITY = 100;                 // Queue max capacity

int *queue_array = new int[CAPACITY];     // Int array that holds the elements
unsigned int queue_size = 0;              // Queue size
unsigned int front = 0;                   // Pointer to head of the queue
unsigned int rear = CAPACITY - 1;         // Pointer to tail of the queue

/**
* Checks, if queue is within the maximum queue capacity.
*/
int isFull()
{
  return (queue_size >= CAPACITY);
}

/**
* Checks, if queue is empty or not.
*/
int isEmpty()
{
  return (queue_size == 0);
}

/**
* Enqueues/Insert an element at the rear of a queue.
* Function returns 1 on success otherwise returns 0.
*/
int enqueue(const int &data)
{
  /// Throws exception if queue is full
  if (isFull())
    throw overflow_error("Error: overflow");

  /// Check overflow
  bool canEnq = false;

  /// Check if queue is not full
  if (!isFull())
  {
    /// Increment tail index
    rear++;
    /// Add item to the queue
    queue_array[rear % CAPACITY] = data;

    canEnq = true;

    /// Increment queue size
    queue_size++;
  }

  return canEnq;
}

/**
* Dequeues/Removes an element from front of the queue.
* It returns the element on success otherwise returns
* INT_MIN as error code.
*/
int dequeue()
{
  // Queue empty error
  if (isEmpty())
    throw underflow_error("Error: underflow");

  int data = INT_MIN;

  /// Check if the queue is not empty
  if (!isEmpty())
  {
    /// Assign the deleted element to temporary variable
    data = queue_array[front % CAPACITY];

    /// Increment head index
    front++;

    /// Decrement queue's size
    queue_size--;
  }

  return data;
}

/**
* Gets, element at rear of the queue. It returns the element
* at rear of the queue on success otherwise return INT_MIN as
* error code.
*/
int getRear()
{
  // Return INT_MIN if queue is empty otherwise rear.
  return (isEmpty()) ? INT_MIN : queue_array[rear];
}

/**
* Gets, element at front of the queue. It returns the element
* at front of the queue on success otherwise return INT_MIN as
* error code.
*/
int getFront()
{
  // Return INT_MIN if queue is empty otherwise front.
  return (isEmpty()) ? INT_MIN : queue_array[front];
}

string prepMenu()
{
  string menu = "";

  menu += " \n-------------------------------------------------------------------\n";
  menu += "1.Enqueue 2.Dequeue 3.Size 4.Get Rear 5.Get Front 6.Display 7.Exit\n";
  menu += "----------------------------------------------------------------------\n";
  menu += "Select an option: ";

  return menu;
}

void display()
{
  for (int i = front; i <= rear; i++)
    cout << queue_array[i] << " ";

  cout << endl << endl;
}

int main()
{
  int option = 0;
  int data = 0;
  string sline = "";

  string menu = prepMenu();

  do
  {
    cout << menu;
    getline(cin, sline);
    stringstream(sline) >> option;

    switch (option)
    {
    case 1:
        cout << "\nEnter data to enqueue (-99 to stop): ";
        getline(cin, sline);
        stringstream(sline) >> data;

        while (data != -99)
        {
          /// Enqueue function returns 1 on success
          /// otherwise 0
          if (enqueue(data))
            cout << "Element added to queue.";
          else
            cout << "Queue is full." << endl;

          cout << "\nEnter data to enqueue (-99 to stop): ";
          getline(cin, sline);
          stringstream(sline) >> data;
        }
      break;

    case 2:
      data = dequeue();

      /// on success dequeue returns element removed
      /// otherwise returns INT_MIN
      if (data == INT_MIN)
        cout << "Queue is empty." << endl;
      else
        cout << "Data => " << data << endl;
      break;

    case 3:
      /// isEmpty() function returns 1 if queue is emtpy
      /// otherwise returns 0
      if (isEmpty())
        cout << "Queue is empty." << endl;
      else
        cout << "Queue queue_size => " << queue_size << endl;
      break;

    case 4:
      data = getRear();

      if (data == INT_MIN)
        cout << "Queue is empty." << endl;
      else
        cout << "Rear => " << data << endl;
      break;

    case 5:
      data = getFront();

      if (data == INT_MIN)
        cout << "Queue is empty." << endl;
      else
        cout << "Front => " << data << endl;
      break;

    case 6:
      display();
      break;

    default:
      cout << "Invalid choice, please input number between (0-7).\n";
      break;
    } 

    cout << endl;

  } while (option != 7);
}