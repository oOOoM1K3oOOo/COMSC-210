/*******************************************************************
Problem: Assignment 11N
Question: Write a program that will display the minimum path between 
          any two vertices in a given graph. The program will input 
          the graph from a file provided by the user. It will prompt 
          the user for entering the name of the start vertex and the
          end vertex. It will find the minimum path between the two 
          vertices. It will display the minimum path showing all the
          vertices along the path. It will also display the total 
          distance along the minimum path.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 05/05/2019

Status: 100% Complete
*******************************************************************/
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Graph.h"

using namespace std;

/*
struct Vertex
{
  int totalDist;
  vector<int> path;
  int pathLength;
};
*/

bool readFile(Graph &graph, const string &fileName)
{
  bool isRead = false;
  int weight = 0;
  int vertNum1 = 0;
  int vertNum2 = 0;
  string sline = "";
  string vertName = "";
  stringstream ss;
  ifstream infile(fileName);

  if (infile)
  {
    while (getline(infile, sline) && ((ss = stringstream(sline)) >> vertNum1 >> skipws) 
          && vertNum1 >= 0)
    {
      ss.ignore(1, '\t');
      getline(ss, vertName);
      graph.addVertex(vertName);
    }

    while (getline(infile, sline) && (stringstream(sline) >> vertNum1 >> vertNum2 >> weight) && vertNum1 >= 0 /*&& (infile >> vertNum2 >> weight)*/ )
    {
      graph.addEdge(vertNum1, vertNum2, weight);
    }

    infile.close();

    isRead = true;
  }
  else
  {
    cout
      << endl
      << "Error: The file '" << fileName << "' is not found."
      << endl;
  }

  return isRead;
}

int main()
{
  string sline = "";
  string end = "";
  Graph graph;

  cout << "Please enter the name of the file to be open: " << endl;
  cout << "--> ";
  getline(cin, sline);

  if (sline != "" && readFile(graph, sline))
  {
    graph.display();

    do
    {
      cout
        << "Please enter the start vertex: (Press enter to exit)"
        << endl
        << "--> ";
      getline(cin, sline);

      if (sline != "")
      {
        cout
          << "Please enter the end vertex:"
          << endl
          << "--> ";
        getline(cin, end);

        graph.MinPath(sline, end);
      }
    } while (sline != "");
  }

  return 0;
}