/*******************************************************************
Problem: Assignment 06N - Single Linked Stack
Question: Please study the code 'Stack as Array example for assignment
          5N' posted in module 6 under assignment header. You need to 
          implement the same class, but this time implement the stack 
          as a single linked list. The test of the class should be 
          done with the same main function as in the example. Please 
          do not change the main function to avoid loosing points.

          Please place head comments AND comments to each function just 
          like in the example for full credit.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/09/2019

Status: 100% Complete
*******************************************************************/
#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <stdexcept>

using namespace std;

template<class Type>
class stackType
{ 
  private: 
    struct nodeType      /// Structure to contain the value and 
                          /// the pointer to the next element
    {
      Type value;
      nodeType *next;
    };

    nodeType *stackTop;  /// Pointer to the top element of the stack
    int list_capacity;   /// Variable to store the maximum stack size
    int list_size;       /// Variable to store the current stack size

    void checkUnderflow() const;
    /// Function to verify if the stack is empty.
    /// Postcondition: Throws an underflow exception if the stack
    ///                is empty.
    
    void checkOverflow() const;
    /// Function to verify if the stack's size will exceed list_capacity.
    /// Postcondition: Throws an underflow exception if the stack
    ///                is empty.

    void copyStack(const stackType<Type> &);
    /// Function to create a copy of the passed stack.
    /// Postcondition: A copy of the passed stack is created
    ///                and assigned to this stack.

    public:
      stackType(const int &stackSize = 100);
      /// constructor
      /// Creates a stack of the size stackSize to hold the stack
      /// elements. The default stack size is 100.

      stackType(const stackType<Type> &);
      /// copy constructor
      /// Creates copy of the passed stack.
      /// Postcondition: A copy of the other stack is created
      ///                and assigned to this stack.

      ~stackType();
      /// destructor
      /// Removes all the elements from the stack.
      /// Postcondtion: Stack's elements are deleted.

      void initializeStack();
      ///Function to initialize the stack to an empty state.
      ///Postcondition: Deletes all the elements in the stack and 
      ///               assigns stackTop = nullprt and list_size = 0.

      int size() const;
      /// Function to return the current size of the list.
      /// Postcondition: Returns stack's current size.

      int capacity() const;
      /// Function to return the list_capacity of the list.
      /// Postcondition: Returns stack's list_capacity.

      bool isEmptyStack() const;
      /// Function to determine whether the stack is empty.
      /// Postcondition: Returns true if the stack if empty,
      ///                otherwise returns false.

      bool isFullStack() const;
      /// Function to determine whether the stack is full.
      /// Postcondition: Returns true if the stack is full,
      ///                otherwise returns false.

      Type top() const;
      /// Function to return the top element of the stack.
      /// Precondition: The stack exists and is not empty.
      /// Postcondition: If the stack is empty, the program will
      ///                throw an underflow exception; otherwise 
      ///                the top element of the stack is returned.

      void push(const Type &);
      /// Function to add newItem to the stack.
      /// Precondition: The stack exists and is not full.
      /// Postcondition: The stack is changed and newItem
      ///                is added to the top of the stack.

      void pop();
      /// Function to removes the top element of the stack.
      /// Precondition: The stack exists and is not empty.
      /// Postcondition: If the stack is empty, the program will
      ///                throw an underflow exception; otherwise 
      ///                the top element of the stack is deleted 
      ///                from the stack.


      const stackType<Type> &operator=(const stackType<Type> &);
      ///Overload the assignment operator.
};

template<class Type>
void stackType<Type>::checkUnderflow() const
{
  if (isEmptyStack())
    throw underflow_error("Error: underflow");
} /// end checkUnderflow

template<class Type>
void stackType<Type>::checkOverflow() const
{
  if (isFullStack())
    throw overflow_error("Error: overflow");    // if the stack is full
} /// end checkOverflow

template<class Type>
void stackType<Type>::copyStack(const stackType<Type> &st)
{
  nodeType *currNode = st.top();
  int currSize = st.size();

  if(!stackTop)                   // if the stack is not empty, 
                                  // empties the stack
    initializeStack();

  list_capacity = st.maxSize();   // assigns the list_capacity of the 
                                  // other stack to this stack

  while (currSize-- && currNode)  // does a deep copy the elements 
                                  // of the other stack to this stack
  {
    push(currNode->value);
    currNode = currNode->next;
  }
} /// end copyStack

template<class Type>
stackType<Type>::stackType(const int &stackSize)
{
  stackTop = nullptr;
  list_size = 0;
  list_capacity = stackSize;
} /// end constructor

template<class Type>
stackType<Type>::stackType(const stackType<Type> &st) : stackType()// Is the inheritance needed here???
{
  copyStack(st);                  // uses class' method to copy the 
                                  // stack
} /// end copy constructor

template<class Type>
stackType<Type>::~stackType()
{
  initializeStack();              // uses class' method to delete all
                                  // stack's elements
} /// end destructor

template<class Type>
void stackType<Type>::initializeStack()
{
  while (!isEmptyStack())         // deletes all the elements until 
                                  // the stack's size is positive and
                                  // non-zero
    pop();
} /// end initializeStack

template<class Type>
int stackType<Type>::size() const
{
  return list_size;            
} /// end size

template<class Type>
int stackType<Type>::capacity() const
{
  return list_capacity;
} /// end list_capacity

template<class Type>
bool stackType<Type>::isEmptyStack() const
{
  return !list_size;              // returns true if list_size = 0
                                  // and false otherwise
} /// end isEmptyStack

template<class Type>
bool stackType<Type>::isFullStack() const
{
  return (list_size == list_capacity);
} /// end isFullStack

template<class Type>
Type stackType<Type>::top() const
{
  checkUnderflow();

  return stackTop->value;         // returns value of stack's top 
                                  // element
}

template<class Type>
void stackType<Type>::push(const Type &obj)
{
  checkOverflow();                // checks if the stack is not full:
                                  // if it's full, the program 
                                  // throws an exception; if it is not -
                                  // the program goes forward

  nodeType *nodeNew = new nodeType; // allocates memory for the new
                                    // element

  nodeNew->value = obj;            // assigns the passed value to the
                                   // new element
  nodeNew->next = nullptr;

  nodeNew->next = stackTop;        // inserts the new element before
                                   // the stackTop

  stackTop = nodeNew;              // sets the stackTop to point to 
                                   // the new element

  list_size++;
} /// end push

template<class Type>
void stackType<Type>::pop()
{
  checkUnderflow();             // checks if the stack is non-empty:
                                // if it is empty, the program 
                                // throws an exception; if it is not -
                                // the program goes forward

  nodeType *tempNode = stackTop; // sets tempNode to point to top
                                 // element

  stackTop = stackTop->next;     // sets stackTop to point to the 
                                 // element next to

  delete tempNode;                   // deletes current top element

  list_size--;                   // decrements stack's size 
} /// end pop

template<class Type>
const stackType<Type> &stackType<Type>::operator=
                                          (const stackType<Type> &st)
{
  if (this != &st)                // if the stack doesn't equal to 
                                  // itself, copies the stack
    copyStack(st);

  return *this;
} /// end operator=

#endif