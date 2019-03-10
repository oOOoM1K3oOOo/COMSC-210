#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <stdexcept>

using namespace std;

template<class Type>
class stackType
{ 
  private: 
    struct StackNode      /// Structure to contain the value and 
                          /// the pointer to the next element
    {
      Type node;
      StackNode *next;
    };

    StackNode *stackTop;  /// Pointer to the top element of the stack
    int capacity;     /// Variable to store the maximum stack size
    int list_size;        /// Variable to store the current stack size

    void checkUnderflow() const;
    /// Function to verify if the stack is empty
    /// Postcondition: Throws an underflow exception if the stack
    ///                is empty.

    void erase(StackNode *);
    /// Function to delete the element from the stack.
    /// Precondition: The stack exists and is not empty.
    /// Postcondition: The stack is changed and the top element is 
    ///                removed from the stack.

    void stackCopy(const stackType<Type> &);
    /// Function to create a copy of the passed stack.
    /// Postcondition: A copy of the passed stack is created
    ///                and assigned to this stack.

    public:
      stackType(const int &stackSize = 100);
      /// constructor
      /// Creates a stack of the size stackSize to hold the stack
      /// elements. The default stack size is 100.

      stackType(const stackType<Type> &): stackType();
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
      /// Function to return the capacity of the list.
      /// Postcondition: Returns stack's capacity.

      bool isEmptyStack() const;
      /// Function to determine whether the stack is empty.
      /// Postcondition: Returns true if the stack if empty,
      ///                otherwise returns false.

      bool isFullStack() const;
      /// Function to determine whether the stack is full.
      /// Postcondition: Returns true if the stack is full,
      ///                otherwise returns false.

      void push(const Type &);
      /// Function to add newItem to the stack.
      /// Precondition: The stack exists and is not full.
      /// Postcondition: The stack is changed and newItem
      ///                is added to the top of the stack.

      Type top() const;
      /// Function to return the top element of the stack.
      /// Precondition: The stack exists and is not empty.
      /// Postcondition: If the stack is empty, the program will
      ///                throw an underflow exception; otherwise 
      ///                the top element of the stack is returned.

      Type pop();
      /// Function to removes and returns the top element of the 
      /// stack.
      /// Precondition: The stack exists and is not empty.
      /// Postcondition: If the stack is empty, the program will
      ///                throw an underflow exception; otherwise 
      ///                the top element of the stack is deleted 
      ///                from the stack and returned.


      const stackType<Type> &operator=(const stackType<Type> &);
      ///Overload the assignment operator.
};

template<class Type>
void stackType<Type>::checkUnderflow() const
{
  if (empty())
    throw underflow_error("Error: underflow");
}

template<class Type>
void stackType<Type>::erase(StackNode *obj)
{
  
}

template<class Type>
void stackType<Type>::stackCopy(const stackType<Type> &st)
{
  initializeStack();

  capacity = st.maxSize();
  StackNode *currNode = st.top();
  int currSize = st.size();

  while (currSize-- && currNode)
  {
    push(currNode->Node);
    currNode = currNode->next;
  }
}

template<class Type>
stackType<Type>::stackType(const int &stackSize)
{
  stackTop = nullptr;
  list_size = 0;
  capacity = stackSize;
}

template<class Type>
stackType<Type>::stackType(const stackType<Type> &st) : stackType()// Is the inheritance needed here???
{
  stackCopy(st);
}

template<class Type>
stackType<Type>::~stackType()
{
  initializeStack();
}

template<class Type>
void stackType<Type>::initializeStack()
{
  while (!isEmptyStack())
    erase(stackTop);
}

template<class Type>
void stackType<Type>

template<class Type>
void stackType<Type>

template<class Type>
void stackType<Type>

template<class Type>
void stackType<Type>

template<class Type>
void stackType<Type>

template<class Type>
void stackType<Type>

#endif