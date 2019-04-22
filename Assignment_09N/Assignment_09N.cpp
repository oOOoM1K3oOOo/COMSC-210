/*******************************************************************
Problem: Assignment 09N
Question: The code given below is incomplete. Please,
          1. Implement the functions ( Note: if you need to add a helper 
             function please do so but you need to explain what you added 
             and why);
          2. Move the function implementations out of the class 
             declaration;
          3. Document what each function does (comments);
          4. Test the resulting class;
          5. Submit as usual.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 04/21/2019

Status: 100% Complete
*******************************************************************/
#include <iostream>

using namespace std;

const int SIZE = 15;

struct BSTNode /// BinarySearchTreeNode
{
  int value;
  BSTNode *left = nullptr;
  BSTNode *right = nullptr;
};

class BST // BinarySearchTree
{
  private:
    BSTNode* root;
  public:
    BST();

   /**
    * Insert a new node into the tree.
    *
    * @param value   A value to be inserted in the tree.
    * @return void.
    */
    void insert(const int &);


   /**
    * Removes specific node from the tree. The tree 
    * contains a node to delete. Three conditions are 
    * accounted: if the node contains no children, 
    * left or right child, and two children. If 
    * the node contains no children, it finds its parent 
    * and sets the child pointer that links to it to nullptr, 
    * then frees the node’s memory. If the node contains left 
    * or right child, then the method links the node’s 
    * subtree with its parent. If the node contains both children,
    * then the method attaches the node’s right subtree to the 
    * parent, then finds a position in the right subtree to 
    * attach the left subtree. 
    *
    * @param value   A value to be removed from the tree.
    * @return void.
    */
    void remove(const int &);

   /**
    * Finds the node with a minimal value.
    *
    * @param value  A value to be inserted in the tree.
    * @return   Pointer to the node with a minimal value.
    */
    BSTNode *finMin() const;

   /**
    * Finds the node with a maximum value.
    *
    * @param value  A value to be inserted in the tree.
    * @return   Pointer to the node with a maximum value.
    */
    BSTNode *finMax() const;

   /**
    * Displays the valued in the subtrees pointed to by 
    * node pointer, via preorder traversal. Preorder
    * traversal means that the tree is traversed by the 
    * pattern: the current node’s data is processed, the 
    * current node’s left subtree is traversed, and the 
    * current node’s right subtree is traversed.
    *
    * @param    Pointer to the node being traversed.
    * @return void.
    */
    void preOrderTraversal() const;
  
    void preOrderTraversal(const BSTNode *) const;
  
    /**
     * Displays the valued in the subtrees pointed to by
     * node pointer, via inorder traversal. Preorder
     * traversal means that the tree is traversed by the
     * pattern: the current node’s left subtree is traversed, 
     * the current node’s data is processed, and the
     * current node’s right subtree is traversed.
     *
     * @param    Pointer to the node being traversed.
     * @return void.
     */
    void inOrderTraversal() const;
  
    void inOrderTraversal(const BSTNode *) const;

    /**
     * Displays the valued in the subtrees pointed to by
     * node pointer, via postorder traversal. Preorder
     * traversal means that the tree is traversed by the
     * pattern: the current node’s left subtree is traversed,
     * the current node’s right subtree is traversed, and
     * the current node’s data is processed.
     *
     * @param    Pointer to the node being traversed.
     * @return void.
     */
    void postOrderTraversal() const;
  
    void postOrderTraversal(const BSTNode *) const;
};

BST::BST()
{
  root = nullptr;
}

void BST::insert(const int &value)
{
  BSTNode **nodePtr = nullptr;
  BSTNode *nodeNew = new BSTNode;
  bool isEqual = false;

  nodeNew->value = value;
  nodeNew->left = nodeNew->right = nullptr;

  if (!root)
    root = nodeNew;
  else
  {
    nodePtr = &root;

    while (*nodePtr && !isEqual)
    {
      isEqual = (value == (*nodePtr)->value);
      nodePtr = (value < (*nodePtr)->value) ? &((**nodePtr).left)
                                            : &((**nodePtr).right);
    }

    !isEqual && (*nodePtr = nodeNew);
  }
}

void BST::remove(const int &value)
{
  BSTNode **nodePtr = &root;
  BSTNode *tempNodePtr = nullptr;

  while (*nodePtr && value != (*nodePtr)->value)
  {
    nodePtr = (value > (*nodePtr)->value) ? &((**nodePtr).right)
                                           : &((**nodePtr).left);
  }

  if (!(*nodePtr))
    cout
        << endl
        << "No element with a value '" << value << "' is found. "
        << "Nothing is deleted."
        << endl;
  else 
  {
    if (!(*nodePtr)->right)
    {
      tempNodePtr = *nodePtr;
      *nodePtr = (*nodePtr)->left;
      delete tempNodePtr;
    }
    else if (!(*nodePtr)->left)
    {
      tempNodePtr = *nodePtr;
      *nodePtr = (*nodePtr)->right;
      delete tempNodePtr;
    }
    else
    {
      // Move one node to the right. 
      tempNodePtr = (*nodePtr)->right;

      // Go to the end left node. 
      while (tempNodePtr->left)
        tempNodePtr = tempNodePtr->left;

      // Reattach the left subtree. 
      tempNodePtr->left = (*nodePtr)->left;
      tempNodePtr = *nodePtr;

      // Reattach the right subtree. 
      *nodePtr = (*nodePtr)->right;

      delete tempNodePtr;
    }
  }
}

BSTNode *BST::finMin() const
{
  BSTNode *nodePtr = root;

  if (!nodePtr)
    throw underflow_error("Error: The tree is empty.");

  while (nodePtr->left && (nodePtr = nodePtr->left));

  return nodePtr;
}

BSTNode *BST::finMax() const
{
  BSTNode *nodePtr = root;

  if (!nodePtr)
    throw underflow_error("Error: The tree is empty.");

  while (nodePtr->right && (nodePtr = nodePtr->right));

  return nodePtr;
}

void BST::preOrderTraversal() const
{
  cout << "preOrderTraversal: ";
  preOrderTraversal(root);
  cout << endl;
}

void BST::preOrderTraversal(const BSTNode *node) const
{
  if (node) {
    cout << node->value << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

void BST::inOrderTraversal() const
{
  cout << "inOrderTraversal: ";
  inOrderTraversal(root);
  cout << endl;
}

void BST::inOrderTraversal(const BSTNode *node) const
{
  if (node) 
  {
    inOrderTraversal(node->left);
    cout << node->value << " ";
    inOrderTraversal(node->right);
  }
}

void BST::postOrderTraversal() const
{
  cout << "postOrderTraversal: ";
  postOrderTraversal(root);
  cout << endl;
}

void BST::postOrderTraversal(const BSTNode *node) const
{
  if (node) 
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->value << " ";
  }
}

int main()
{
  BST bst;
  int values[SIZE] = { 5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12 };
  for (int i = 0; i < SIZE; i++)
    bst.insert(values[i]);

  cout << "Tree before the elements are removed:" << endl;
  bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
  bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
  bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5

  cout << endl << "Removing 3..." << endl;
  bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;

  cout << "Removing -4..." << endl;
  bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;

  cout << "Removing 12..." << endl;
  bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete

  cout << endl << "Tree after the elements are removed:" << endl;
  bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
  bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
  bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5

  return 0;
}