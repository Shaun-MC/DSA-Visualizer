#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "BinaryTreeInterface.h"

using namespace std;

class BinarySearchTree : public BinaryTreeInterface {
 public:
  
  // Constructors - Destructors
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& rval);

  virtual ~BinarySearchTree();
  
  // Getter - Setters
  int getHeight();
  int getNumberOfNodes();

  int getRootData();

  void setRootData(const int& new_data);

  // Actions    
  bool IsEmpty();

  virtual bool Insert(const int& data);

  void Retrieve(const int& target, int& ret) const;

  bool Contains(const int& target) const;

  virtual bool Remove(const int& data);

  void Clear();

  // Traversal Algorithms - Currently only Display Values
  void PreorderTraverse() const;
  void InorderTraverse() const;
  void PostOrderTraverse() const;

  // Operator Overloads

  void operator = (const BinarySearchTree& rval);

  protected:

  private:
  
  TreeNode* InsertHelper(TreeNode*& curr_node, const int& data);
  void RetrieveHelper(TreeNode* curr_node, const int& target, int& ret) const;
  TreeNode* RemoveHelper(TreeNode*& curr_node, const int& data);

  void ClearHelper(TreeNode*& curr_node);

  void PreorderTraverseHelper(TreeNode* curr_node) const;
  void InorderTraverseHelper(TreeNode* curr_node) const;
  void PostOrderTraverseHelper(TreeNode* curr_node) const;

  TreeNode* AssignmentOperatorHelper(TreeNode*& curr_node, TreeNode* rval_curr_node);
};

#endif