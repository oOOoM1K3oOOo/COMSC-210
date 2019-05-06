/*******************************************************************
Problem: Assignment 10N
Question: The clients are arriving to get passports. The arriving
          clients register at the window. Each arriving client has
          a priority number and name. The priority numbers vary from
          1 to 10. Ten being the highest priority and 1 being the
          lowest. At 10:00 am, the passport office will start serving
          clients that had registered by then at the window. The clients
          will be served not in the order that they arrived but in the
          order of their priority. First, all with priority 10; then
          those with priority 9 and so on.

          To simulate the above, create an array based  priority queue
          using max heap. Input registering clients one by one and enque
          them one by one into the priority queue.  Each client input
          data will consist of client priority and name. Priority of -1
          will indicate end of data. After all the clients are enqued,
          deque them from the priority queue one by one and display them
          one by one till priority queue becomes empty. See the test input
          data and  the expected output below.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 04/28/2019

Status: 100% Complete
*******************************************************************/
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

const int MAX_PRIORITY = 10;

/*
    Class Definition
*/

struct Node
{
  int priority;
  string name;
};

class Priority_queue
{
private:
  vector<Node> heap_vector;
  int lastIndex;
  void maxreheapifyUpward();
  void maxreheapifyDownward();
  int findLargeChildIndex(const int &) const;
public:
  Priority_queue();
  void penque(const string &, const int &);
  Node pdeque();
  bool isEmpty() const;
};

/*
    Class Declaration
*/

void Priority_queue::maxreheapifyUpward()
{
  int chIndex = lastIndex;
  int prIndex = 0;

  while (chIndex > 0 && ((prIndex = chIndex / 2) >= 0 &&
        heap_vector.at(chIndex).priority > heap_vector.at(prIndex).priority))
  {
    //swap values at child and at parent.
    swap(heap_vector.at(chIndex), heap_vector.at(prIndex));

    //Update child to parent
    chIndex = prIndex;
  }
}

void Priority_queue::maxreheapifyDownward()
{
  int parentIndex = 0;
  int largeChildIndex = 0;

  ///cout << "hi maxreheapifyDownward" << endl;

  while (parentIndex < lastIndex &&
    (largeChildIndex = findLargeChildIndex(parentIndex)) > 0 &&
    heap_vector.at(largeChildIndex).priority > heap_vector.at(parentIndex).priority)
  {
    ///cout << "hi maxreheapifyDownward 2" << endl;
    ///swap value at parentIndex with value at largeChildIndex
    swap(heap_vector.at(parentIndex), heap_vector.at(largeChildIndex));

    ///update parentIndex
    parentIndex = largeChildIndex;
  }
}

int Priority_queue::findLargeChildIndex(const int &parentIndex) const
{
  int lChIndex = (2 * parentIndex) + 1;
  int rChIndex = (2 * parentIndex) + 2;
  int rtnIndex = -1;

  //case both children exist
  if (rChIndex <= lastIndex && lChIndex <= lastIndex)
  {
    ///compare value at rChIndex and at lChIndex
    ///return the index where the value is smaller
    rtnIndex = (heap_vector.at(rChIndex).priority > heap_vector.at(lChIndex).priority) ?
      rChIndex : lChIndex;
  }
  ///case only left child exist
  else if (lChIndex <= lastIndex)
  {
    rtnIndex = lChIndex;
  }

  return rtnIndex;
}

Priority_queue::Priority_queue()
{
  lastIndex = -1;
}

void Priority_queue::penque(const string &name, const int &priority)
{
  Node newClient = { priority, name };

  heap_vector.push_back(newClient);
  lastIndex++;
  maxreheapifyUpward();
}

Node Priority_queue::pdeque()
{
  if (isEmpty())
    throw underflow_error("Error: No elements in the vector.");

  Node temp = heap_vector.at(0);

  heap_vector.at(0) = heap_vector.at(lastIndex--);
  heap_vector.pop_back();
  maxreheapifyDownward();

  return temp;
}

bool Priority_queue::isEmpty() const
{
  return lastIndex == -1;
}

int main()
{
  string sline = "";
  int priority;
  int count = 0;
  string name;
  Priority_queue q;

  cout << "Welcome to the Client Registry! To register clients, " 
       << endl 
       << "please enter client's information one by one, first by "
       << "entering client's name and his priority."
       << endl << endl;

  cout << "Please enter client's information for each one by one."
    << "To stop the registry, please enter '-1'."
    << endl;

  do
  {
    priority = -2;
    name = "";

    cout << "Client #" << count << ": ";
    getline(cin, sline);
    stringstream(sline) >> priority >> name;

    if (priority < -1 || priority > MAX_PRIORITY)
      cout
      << endl
      << "Invalid priority. Please enter client's information again."
      << endl;
    else if (sline == "" || priority != -1 )
    {
      q.penque(name, priority);
      count++;
    }
  } while (priority != -1);

  cout 
    << endl 
    << "Client's list after the sorting with priority: " 
    << endl;

  while (!q.isEmpty())
  {
    Node client = q.pdeque();
    cout << client.priority << " " << client.name << endl;
  }

  return 0;
}
#endif