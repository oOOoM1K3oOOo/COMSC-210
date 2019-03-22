///---------------------------------------------------------------
/// File: LListQueue.cpp
/// Purpose: Implementation file for a demonstration of a queue
///        implemented as an array.    Data type: Character
/// Programming Language: C++
///---------------------------------------------------------------
#include "LListQueue.h"


///--------------------------------------------
/// Function: LListQueue()
/// Purpose: Class constructor
/// Returns: void
///--------------------------------------------
LListQueue::LListQueue()
{
    head = tail = nullptr;
}

///--------------------------------------------
/// Function: Code137_Queue()
/// Purpose: Class destructor
/// Returns: void
///--------------------------------------------
LListQueue::~LListQueue()
{
    ClearQueue();
}

///--------------------------------------------
/// Function: ClearQueue()
/// Purpose: Remove all items from the queue
/// Returns: void
///--------------------------------------------
void LListQueue::ClearQueue()
{
    QNode *temp;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = tail = nullptr; // Reset indices to start over
}

///--------------------------------------------
/// Function: Enqueue()
/// Purpose: Enqueue an item into the queue.
/// Returns: true if enqueue was successful
///        or false if the enqueue failed.
///--------------------------------------------
bool LListQueue::Enqueue(char ch)
{
    QNode *temp;

    /// Check to see if the Queue is full
    if(isFull()) return false;

    /// Create new node for the queue
    temp = new QNode ();
    temp->ch = ch;
    temp->next = nullptr;

    /// Check for inserting first in the queue
    if(head == nullptr)
        head = tail = temp;
    else
    {
        tail->next = temp; /// Insert into the queue
        tail = temp;       /// Set tail to new last node
    }

    return true;
}

///--------------------------------------------
/// Function: Dequeue()
/// Purpose: Dequeue an item from the Queue.
/// Returns: Character being dequeued or '\0'
///   if dequeue failed.
//--------------------------------------------
char LListQueue::Dequeue()
{
    char ch;
    QNode *temp;

    /// Check for empty Queue
    if(isEmpty()) return '\0';  /// Return null character if queue is empty
    else
    {
        ch = head->ch;        /// Get character to return
        temp = head;
        head = head->next;    /// Advance head pointer
        delete temp;            /// Free old head
        /// Check to see if queue is empty
        if(isEmpty())
        {
            head = tail = nullptr;        /// Reset everything to empty queue
        }
    }
    return ch;                /// Return popped character
}

///--------------------------------------------
/// Function: isEmpty()
/// Purpose: Return true if the queue is empty
/// Returns: true if empty, otherwise false
///--------------------------------------------
bool LListQueue::isEmpty()
{
    return (head == nullptr);
}

///--------------------------------------------
/// Function: isFull()
/// Purpose: Return true if the queue is full
/// Returns: true if full, otherwise false
///--------------------------------------------
bool LListQueue::isFull()
{
    return false;
}
