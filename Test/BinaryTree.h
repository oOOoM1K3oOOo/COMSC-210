#ifndef _H_INCLUDED
#define _H_INCLUDED
///---------------------------------------------------------------
/// File:BinaryTree.h
/// Purpose: Header file for a demonstration of a binary tree
///---------------------------------------------------------------


#include <iostream>
using namespace std;

/// Define a structure to be used as the tree node
struct TreeNode
{
  int      Key;
  float    fValue;
  int      iValue;
  char     cArray[7];
  TreeNode *left;
  TreeNode *right;
};

class BinaryTree
{
private:
  TreeNode *root;

public:
  BinaryTree();
  ~BinaryTree();
  bool isEmpty();
  TreeNode *SearchTree(int Key);
  int Insert(TreeNode *newNode);
  int Insert(int Key, float f, int i, const char *cA);
  int Delete(int Key);
  void PrintOne(TreeNode *T);
  void PrintTree();
private:
  void ClearTree(TreeNode *T);
  TreeNode *DupNode(TreeNode * T);
  void PrintAll(TreeNode *T);
};



#endif // _H_INCLUDED
