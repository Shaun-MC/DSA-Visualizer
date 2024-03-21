#include "BinarySearchTree.h"

// Constructors - Destructors
BinarySearchTree::BinarySearchTree() {
    
    this->root = nullptr;
    this->node_count = 0;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& rval) { // UNTESTED
    
    if (rval.root == nullptr) {
        
        this->root = nullptr;
        this->node_count = 0;
    } else {
        
        *this = rval;
        this->node_count = rval.node_count;
    }
}

BinarySearchTree::~BinarySearchTree() {
    
    this->Clear();
}

// Getter - Setters
int BinarySearchTree::getHeight() {
    
    if (this->root == nullptr) {
        
        return 0;
    } else {
        
        return this->root->getHeight();
    }
}

int BinarySearchTree::getNumberOfNodes() {
    
    return this->node_count;
}

int BinarySearchTree::getRootData() {
        
    if (this->root == nullptr) {
        
        throw std::runtime_error("getRootData() called on empty tree");
    } else {
        
        return this->root->getValue();
    }
}

void BinarySearchTree::setRootData(const int& new_data) {
    
    if (this->root == nullptr) {
        
        this->root = new TreeNode(new_data);
    } else {
        
        this->root->setValue(new_data);
    }
}

// Actions
bool BinarySearchTree::IsEmpty() {
    
    return (this->root == nullptr);
}

bool BinarySearchTree::Insert(const int& data) { // UNTESTED
    
    if (this->root == nullptr) {
        
        this->root = new TreeNode(data);
        this->node_count++;
        return true;
    } else {
        
        const int old_count = this->node_count;

        this->root = InsertHelper(this->root, data);

        return old_count != this->node_count;
    }
}

BinaryTreeInterface::TreeNode* BinarySearchTree::InsertHelper(TreeNode*& curr_node, const int& data) { // UNTESTED

    if (curr_node == nullptr) {
        
        curr_node = new TreeNode(data);
        this->node_count++;
        
    } else if (data == curr_node->getValue()) {

        return curr_node;
    } else if (data < curr_node->getValue()) {
        
        curr_node->left_child = InsertHelper(curr_node->left_child, data);
    } else {
        
        curr_node->right_child = InsertHelper(curr_node->right_child, data);
    } 
}

void BinarySearchTree::Retrieve(const int& target, int& ret) const { // UNTESTED
    
    if (this->root == nullptr) {
        
        throw std::runtime_error("Retrieve() called on empty tree");
    } else {
        
        RetrieveHelper(this->root, target, ret);
    }
}

void BinarySearchTree::RetrieveHelper(TreeNode* curr_node, const int& target, int& ret) const { // UNTESTED

    if (curr_node == nullptr) {

        return;
    } else if (target == curr_node->getValue()) {

        ret = curr_node->getValue();
    } else if (target < curr_node->getValue()) {

        RetrieveHelper(curr_node->left_child, target, ret);
    } else {

        RetrieveHelper(curr_node->right_child, target, ret);
    }
}

bool BinarySearchTree::Contains(const int& target) const { // UNTESTED
    
    if (this->root == nullptr) {
        
        return false;
    } else {
        
        int ret = 0;
        RetrieveHelper(this->root, target, ret);
        return ret == target;
    }
}

bool BinarySearchTree::Remove(const int& data) { // UNTESTED
    
    if (this->root == nullptr) {
        
        return false;
    } else {
        
        const int old_count = this->node_count;
        
        this->root = RemoveHelper(this->root, data);
        
        return old_count != this->node_count;
    }
}

// UNTESTED - REVIEW
BinarySearchTree::TreeNode* BinarySearchTree::RemoveHelper(TreeNode*& curr_node, const int& data) {

    if (curr_node == nullptr) {
        
        return nullptr;
    } else if (data == curr_node->getValue()) {
        
        if (curr_node->IsLeaf()) {
            
            delete curr_node;
            curr_node = nullptr;
            this->node_count--;
        } else if (curr_node->left_child == nullptr) {
           
            TreeNode* temp = curr_node;
            curr_node = curr_node->right_child;
            temp->right_child = nullptr;
            delete temp;
            this->node_count--;
        } else if (curr_node->right_child == nullptr) {
            
            TreeNode* temp = curr_node;
            curr_node = curr_node->left_child;
            temp->left_child = nullptr;
            delete temp;
            this->node_count--;
        } else {
            
            int replacement = 0;
            TreeNode* temp = curr_node->left_child;
            while (temp->right_child != nullptr) {
                
                temp = temp->right_child;
            }
            replacement = temp->getValue();
            curr_node->setValue(replacement);
            curr_node->left_child = RemoveHelper(curr_node->left_child, replacement);
        }
    } else if (data < curr_node->getValue()) {
        
        curr_node->left_child = RemoveHelper(curr_node->left_child, data);
    } else {
        
        curr_node->right_child = RemoveHelper(curr_node->right_child, data);
    }
}

void BinarySearchTree::Clear() { // UNTESTED
    
    ClearHelper(this->root);
}

void BinarySearchTree::ClearHelper(TreeNode*& curr_node) { // UNTESTED
    
    if (curr_node == nullptr) {
        
        return;
    } 

    ClearHelper(curr_node->left_child);
    ClearHelper(curr_node->right_child);

    delete curr_node;
    curr_node = nullptr;
    --this->node_count;
}

// Traversal Algorithms
void BinarySearchTree::PreorderTraverse() const { // UNTESTED
    
    if (this->root == nullptr) {

        return;
    } else {

        PreorderTraverseHelper(this->root);
    }
}

void BinarySearchTree::PreorderTraverseHelper(TreeNode* curr_node) const { // UNTESTED
    
    if (curr_node == nullptr) {
        
        return;
    } else {
        
        cout << curr_node->getValue() << " ";
        
        PreorderTraverseHelper(curr_node->left_child);
        PreorderTraverseHelper(curr_node->right_child);
    }
}

void BinarySearchTree::InorderTraverse() const { // UNTESTED
    
    if (this->root == nullptr) {

        return;
    } else {

        InorderTraverseHelper(this->root);
    }
}

void BinarySearchTree::InorderTraverseHelper(TreeNode* curr_node) const { // UNTESTED
    
    if (curr_node == nullptr) {
        
        return;
    } else {
        
        InorderTraverseHelper(curr_node->left_child);
        
        cout << curr_node->getValue() << " ";
        
        InorderTraverseHelper(curr_node->right_child);
    }
}

void BinarySearchTree::PostOrderTraverse() const { // UNTESTED
    
    if (this->root == nullptr) {

        return;
    } else {

        PostOrderTraverseHelper(this->root);
    }
}

void BinarySearchTree::PostOrderTraverseHelper(TreeNode* curr_node) const { // UNTESTED
    
    if (curr_node == nullptr) {
        
        return;
    } else {
        
        PostOrderTraverseHelper(curr_node->left_child);
        PostOrderTraverseHelper(curr_node->right_child);
        
        cout << curr_node->getValue() << " ";
    }
}  

// Operator Overloads
void BinarySearchTree::operator = (const BinarySearchTree& rval) { // UNTESTED
    

    if (this == &rval) {

        return;
    } 
    
    this->Clear();

    if (rval.root == nullptr) {

        return;
    } else {

        this->root = AssignmentOperatorHelper(this->root, rval.root);
    }
}

BinarySearchTree::TreeNode* BinarySearchTree::AssignmentOperatorHelper(TreeNode*& curr_node, TreeNode* rval_curr_node) { // UNTESTED

    if (rval_curr_node == nullptr) {
        
        return nullptr;
    } else {
        
        curr_node = new TreeNode(rval_curr_node->getValue());
        
        curr_node->left_child = AssignmentOperatorHelper(curr_node->left_child, rval_curr_node->left_child);
        curr_node->right_child = AssignmentOperatorHelper(curr_node->right_child, rval_curr_node->right_child);
    }
}
