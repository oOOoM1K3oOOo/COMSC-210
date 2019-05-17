/*******************************************************************
Problem: Assignment 11N - Graph Class
Description: Creates a graph with vertices and edges.
            
            Note: Because I used the recommended BreadthFirst traversal
                  algorithm, the MinPath method searches for the smallest
                  number of vertices to get to the desired vertex, but not
                  for the smallest distance.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 05/05/2019

Status: 100% Complete
*******************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Vertex.h"
#include "PmainQ.h"

#include <iostream>
#include <iomanip>

using namespace std;

class Graph
{
private:
  vector<string> vertices;
  vector<vector<int>> *edges;
  void initEdges();
  void getAdjacentQ(const int &, PmainQ<int> &);

public:
  Graph();
  ~Graph();
  void addVertex(const string &);
  void addEdge(const int &, const int &, const int &);
  void MinPath(const string &, const string &);
  int findVertex(const string &);
  int size() const;
  void display();
};

void Graph::initEdges()
{
  edges = new vector<vector<int>>(vertices.size(), vector<int>(vertices.size(), 0));    //????
}

void Graph::getAdjacentQ(const int &idx, PmainQ<int> &adjQ)
{
  for (int i = 0; i < edges->at(idx).size(); i++)
    if (edges->at(idx).at(i) > 0)
      adjQ.penque(i);
}

Graph::Graph()
{
  edges = nullptr;
}

Graph::~Graph()
{
  delete edges;
}

void Graph::addVertex(const string &vertex)
{
  vertices.push_back(vertex);
}

void Graph::addEdge(const int &from, const int &to, const int &weight)
{
  if (!edges)
    initEdges();

  edges->at(from).at(to) = edges->at(to).at(from) = weight;
}

void Graph::MinPath(const string &from, const string &to)
{
  int fromIdx = findVertex(from);
  int toIdx = findVertex(to);

  if (fromIdx == -1 || toIdx == -1)
  {
    cout
      << endl << "Error: Requested vertex not found: "
      << ((fromIdx == -1) ? ("'" + from + "'") : "")
      << ((toIdx == -1) ? (" '" + to + "'") : "")
      << endl << endl;
  }
  else
  {
    int pI = 0;
    int pDist = 0;
    int pPathLen = 0;
    bool isFound = false;
    vector<bool> visited(vertices.size(), false);
    Vertex vertex(0, { fromIdx });
    PmainQ<Vertex> queue;
    PmainQ<int> adjQ;

    queue.penque(vertex);
    visited.at(fromIdx) = true;

    while (!queue.isEmpty() && !isFound)
    {
      vertex = queue.pdeque();

      pDist = vertex.getTotalDist();
      pPathLen = vertex.getPathLength();
      pI = vertex.getPath().at(pPathLen - 1);

      // getAdjacentQ((pPathLen - 1), adjQ);
      getAdjacentQ((pI), adjQ);

      while (!adjQ.isEmpty() && !isFound)
      {
        int i = adjQ.pdeque();

        if (!visited.at(i))
        {
          visited.at(i) = true;

          Vertex temp((vertex.getTotalDist() + edges->at(pI).at(i)), vertex.getPath());
          temp.addPath(i);
          queue.penque(temp);
          if (i == toIdx) 
          {
            isFound = true;
            vertex = temp;
          }
        }
      }
    }

    if (isFound)
    {
      cout << "Minimal path from '" << from << "' to '" << to << "': ";
      for (int vtxIndex : vertex.getPath())
      {
        cout << vertices.at(vtxIndex) << " ";
      }

      cout << vertex.getTotalDist() << endl << endl;
    }
    else
      cout << "Target is not found" << endl;
  }
}

int Graph::findVertex(const string &vertex)
{
  int count = 0;

  while (count < vertices.size() && vertices.at(count++) != vertex);

  return (count == vertices.size() && vertices.at(count - 1) != vertex) ? -1 : (count - 1);
}


int Graph::size() const
{
  return vertices.size();
}

void Graph::display()
{
  cout << endl << "Graph: " << endl;

  for (int i = 0; i < vertices.size(); i++)
  {
    cout << setw(4) << i << ":  " << setw(13) << vertices.at(i) << ";  [ ";

    for (int j = 0; j < edges->at(i).size(); j++)
    {
      (edges->at(i).at(j) > 0) && 
        cout << "( " << vertices.at(j) << ", " 
             << edges->at(i).at(j) << " ) ";
    }

    cout << "]" << endl;
  }

  cout << endl;
}

#endif
