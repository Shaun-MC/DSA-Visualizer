/**
 * 
 * Code For Interfaces is Directly Inspired by Carrano & Wells Textbook
 * 
 */

// Only Works For Ints ATM

#include <algorithm>

using namespace std;

#ifndef BINARYTREEINTERFACE_H
#define BINARYTREEINTERFACE_H

class BinaryTreeInterface {
 public:

  // Constructors - Destructors
  BinaryTreeInterface() {};

  virtual ~BinaryTreeInterface() = 0;

  // Getter - Setters
  virtual int getHeight() = 0;

  virtual int getNumberOfNodes() = 0;

  virtual int getRootData() = 0;

  virtual void setRootData(const int& new_data) = 0;

  // Actions
  virtual bool IsEmpty() = 0;

  virtual bool Insert(const int& data) = 0;

  virtual bool Remove(const int& data) = 0;

  virtual void Clear() = 0;

  virtual void Retrieve(const int& target, int& ret) const = 0;

  virtual bool Contains(const int& target) const = 0;

  // Traversal Algorithms
  virtual void PreorderTraverse(void visit(int&)) const = 0;

  virtual void InorderTraverse(void visit(int&)) const = 0;

  virtual void PostOrderTraverse(void visit(int&)) const = 0;
 
 protected: 

  class TreeNode {
   public:

    // Constructors - Destructors
    TreeNode() : left_child(nullptr), right_child(nullptr), value(0), height(0) {};
    TreeNode(const int& value) : left_child(nullptr), right_child(nullptr), value(value), height(0) {};
    ~TreeNode() { delete left_child; delete right_child; };

    // Getters - Setters
    int getValue() const { return value; };
    int getHeight() const { return height; };

    void setValue(const int& new_value) { value = new_value; };
    void setHeight(const int& new_height) { height = new_height; };

    // Actions
    bool IsLeaf() const { return (left_child == nullptr && right_child == nullptr); };
    void UpdateHeight() { height = 1 + std::max(left_child->getHeight(), right_child->getHeight()); };

    // Member Data
    TreeNode* left_child;
    TreeNode* right_child; 

    int value;
    int height;
  };

  TreeNode* root;

  int node_count;
};

#endif
