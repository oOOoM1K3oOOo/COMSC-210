/**
* Queue implementation using linked list C style implementation ( no OOP).
*/

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>


#define CAPACITY 100 // Queue max capacity

using namespace std;
/** Queue structure definition */
struct QueueType
{
  int data;
  struct QueueType * next;
};
/** Queue size */
unsigned int size = 0;


int enqueue(QueueType * &rear, QueueType * &front, int data);
int dequeue(QueueType * &front);
int getRear(QueueType * &rear);
int getFront(QueueType * &front);
void display(QueueType * front);
int isEmpty();
int isFull();
string prepMenu();


int main()
{
  int option, data;

  QueueType *rear, *front;

  rear = NULL;
  front = NULL;
  string menu = prepMenu();
  cout << menu << endl;
  cin >> option;
  while (option != 7)
  {

    switch (option)
    {
    case 1:
      cout << "\nEnter data to enqueue (-99 to stop): ";
      cin >> data;
      while (data != -99)
      {
        /// Enqueue function returns 1 on success
        /// otherwise 0
        if (enqueue(rear, front, data))
          cout << "Element added to queue.";
        else
          cout << "Queue is full." << endl;
        cout << "\nEnter data to enqueue (-99 to stop): ";
        cin >> data;
      }


      break;

    case 2:
      data = dequeue(front);

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
        cout << "Queue size => " << size << endl;

      break;

    case 4:
      data = getRear(rear);

      if (data == INT_MIN)
        cout << "Queue is empty." << endl;
      else
        cout << "Rear => " << data << endl;

      break;

    case 5:

      data = getFront(front);

      if (data == INT_MIN)
        cout << "Queue is empty." << endl;
      else
        cout << "Front => " << data << endl;

      break;

    case 6:
      display(front);
      break;

    default:
      cout << "Invalid choice, please input number between (0-5).\n";
      break;
    }

    cout << "\n\n";
    cout << menu << endl;
    cin >> option;
  }
}



/**
* Enqueues/Insert an element at the rear of a queue.
* Function returns 1 on success otherwise returns 0.
*/
int enqueue(QueueType * &rear, QueueType * &front, int data)
{
  QueueType * newNode = NULL;

  /// Check queue out of capacity error
  if (isFull())
  {
    return 0;
  }

  /// Create a new node of queue type
  newNode = new QueueType;

  /// Assign data to new node
  newNode->data = data;

  /// Initially new node does not point anything
  newNode->next = NULL;

  /// Link new node with existing last node
  if ((rear))
  {
    rear->next = newNode;
  }


  /// Make sure newly created node is at rear
  rear = newNode;

  /// Link first node to front if its NULL
  if (!(front))
  {
    front = rear;
  }

  /// Increment quque size
  size++;

  return 1;
}


/**
* Dequeues/Removes an element from front of the queue.
* It returns the element on success otherwise returns
* INT_MIN as error code.
*/
int dequeue(QueueType * &front)
{
  QueueType *toDequque = NULL;
  int data = INT_MIN;

  // Queue empty error
  if (isEmpty())
  {
    return INT_MIN;
  }

  /// Get element and data to dequeue
  toDequque = front;
  data = toDequque->data;

  /// Move front ahead
  front = (front)->next;

  /// Decrement size
  size--;

  /// Clear dequeued element from memory
  free(toDequque);

  return data;
}


/**
* Gets, element at rear of the queue. It returns the element
* at rear of the queue on success otherwise return INT_MIN as
* error code.
*/
int getRear(QueueType * & rear)
{
  // Return INT_MIN if queue is empty otherwise rear.
  return (isEmpty())
    ? INT_MIN
    : rear->data;
}


/**
* Gets, element at front of the queue. It returns the element
* at front of the queue on success otherwise return INT_MIN as
* error code.
*/
int getFront(QueueType * &front)
{
  // Return INT_MIN if queue is empty otherwise front.
  return (isEmpty())
    ? INT_MIN
    : front->data;
}


/**
* Checks, if queue is empty or not.
*/
int isEmpty()
{
  return (size <= 0);
}


/**
* Checks, if queue is within the maximum queue capacity.
*/
int isFull()
{
  return (size > CAPACITY);
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
void display(QueueType * front)
{
  for (QueueType *t = front; t != NULL; t = t->next)
    cout << t->data << " ";
  cout << endl << endl;
}