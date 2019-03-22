#ifndef LLISTQUEUE_H_INCLUDED
#define LLISTQUEUE_H_INCLUDED
///---------------------------------------------------------------
/// File: LListQueue.h
/// Purpose: Header file for a demonstration of a queue implemented
///        as a linked structure.  Data type: Character
/// Programming Language: C++
///---------------------------------------------------------------

struct QNode
{
    char  ch;
    QNode *next;
};

class LListQueue
{
    private:
        QNode *head, *tail;         /// Pointers to head and tail of the queue

    public:
        LListQueue();              /// Class constructor
        ~LListQueue();             /// Class destuctor
        void ClearQueue();          /// Remove all items from the queue
        bool Enqueue(char ch);      /// Enter an item in the queue
        char Dequeue();             /// Remove an item from the queue
        bool isEmpty();             /// Return true if queue is empty
        bool isFull();              /// Return true if queue is full
};




#endif /// LLISTQUEUE_H_INCLUDED
