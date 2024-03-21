#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinarySearchTree.h"

class AVLTree : public BinarySearchTree {
 public:
  
  // Constructors - Destructors
  AVLTree();
  AVLTree(const AVLTree& rval);
  
  ~AVLTree();

  // Actions
  bool Insert(const int& data);

  bool Remove(const int& data);
  
 protected:
  
 private:
  
  // Getter
  int getBalanceFactor(TreeNode*& node);

  // Actions
  void ExecuteRotation(const int bf, TreeNode*& curr, const int& val);

  void LeftLeftRotation(TreeNode*& U);
  void RightRightRotation(TreeNode*& U);

  void LeftRightRotation(TreeNode*& U);
  void RightLeftRotation(TreeNode*& U);

    // Helper Functions
  TreeNode* InsertHelper(TreeNode*& curr_node, const int& data);
  TreeNode* RemoveHelper(TreeNode*& curr_node, const int& data);
};

#endif