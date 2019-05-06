/*******************************************************************
Problem: Assignment 11N - Vertex
Description: Stores the entries, i.e. total distance from the starting 
             point, index of elements which create a path, and the path
             length.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 05/05/2019

Status: 100% Complete
*******************************************************************/
#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

class Vertex
{
  private:
    int totalDist;
    vector<int> path;
    int pathLength;

  public:
    Vertex();
    Vertex(const int &, const vector<int> &);
    int getTotalDist() const;
    vector<int> getPath() const;
    int getPathLength() const;
    void setTotalDist(const int &);
    void setPath(const vector<int> &);
    void addPath(const int &);
    bool operator<(const Vertex &) const;
};

Vertex::Vertex()
{
  totalDist = 0;
  pathLength = 0;
}

Vertex::Vertex(const int &tD, const vector<int> &p)
{
  totalDist = tD;
  path = vector<int>(p);
  pathLength = path.size();
}

int Vertex::getTotalDist() const
{
  return totalDist;
}

vector<int> Vertex::getPath() const
{
  return path;
}

int Vertex::getPathLength() const
{
  return pathLength;
}

void Vertex::setTotalDist(const int &tD)
{
  totalDist = tD;
}

void Vertex::setPath(const vector<int> &p)
{
  path = vector<int>(p);
  pathLength = path.size();
}

void Vertex::addPath(const int &index)
{
  path.push_back(index);
  pathLength++;
}

bool Vertex::operator<(const Vertex &vertex) const 
{
  return totalDist < vertex.getTotalDist();
}

#endif