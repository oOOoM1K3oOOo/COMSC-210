/*******************************************************************
Problem: Assignment 04N
Description: Write a recursive function that describes instructions
              for a solution to this problem. We don’t have graphics
              available, so you should output a sequence of instructions
              that will solve the problem.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 2/23/19

Status: 100% Complete
*******************************************************************/
#include <string>
#include <chrono>
#include <sstream>
#include <iostream>

using namespace std;

void moveDisks(int n, char fromTower, char toTower, char tempTower)
{
  if (n > 0)
  {
    moveDisks(n - 1, fromTower, tempTower, toTower);

    cout
      << "Moving disk " << n << " from " << fromTower << " to "
      << toTower << "."
      << endl;

    moveDisks(n - 1, tempTower, toTower, fromTower);
  }
}

int main()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();

  char fromTower = 'A';
  char tempTower = 'B';
  char toTower = 'C';
  string sline = "";
  int numDisks = 0;

  cout << "Tower of Hanoi:" << endl;

  cout << "Please enter the number of disks to play: ";
  getline(cin, sline);
  stringstream(sline) >> numDisks;

  moveDisks(numDisks, fromTower, toTower, tempTower);

  chrono::system_clock::time_point stop = chrono::system_clock::now();
  double duration = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

  duration *= 1e-3;

  cout
    << endl
    << "Execution time: " << duration << " s"
    << endl;

  cout
    << "Please enter a key to exit..."
    << endl;
  getline(cin, sline);

  return 0;
}