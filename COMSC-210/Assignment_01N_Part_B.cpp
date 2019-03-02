/*******************************************************************
Problem: Assignment 01N Part B - Cylinder Class
Question: Convert the code into a Cylinder class. Show how to convert
          the main() function so it uses your new class.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 02/02/2019

Status: 100% Complete
*******************************************************************/
#include "Cylinder.h"
#include <iostream>

using namespace std;

int main()
{
  Cylinder cylinder;

  cylinder.init(10, 20);

  cout
    << "The volume of a cylinder with radius "
    << cylinder.getRadius() << " and height "
    << cylinder.getHeight() << " is: "
    << cylinder.getVolume()
    << endl;

  return 0;
}