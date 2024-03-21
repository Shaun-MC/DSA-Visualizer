#include "AVLTree.h"

// Constructors - Destructor
AVLTree::AVLTree() : BinarySearchTree() {};

AVLTree::AVLTree(const AVLTree& rval) : BinarySearchTree(rval) {};

AVLTree::~AVLTree() {

    this->Clear();
}

// Actions
bool AVLTree::Insert(const int& data) {

    const int old_count = this->node_count;

    this->root = InsertHelper(this->root, data);

    return (old_count != this->node_count);
}

AVLTree::TreeNode* AVLTree::InsertHelper(TreeNode*& curr, const int& data) {

    if (curr == nullptr) {

        curr = new TreeNode(data);
        ++this->node_count;

    } else if (data <= curr->getValue()) {

        curr->left_child = InsertHelper(curr->left_child, data);

    } else {

        curr->right_child = InsertHelper(curr->right_child, data);
    }

    curr->UpdateHeight();

    const int balance_factor = this->getBalanceFactor(curr);

    switch (balance_factor) {

        case 0:
        case -1:
        case 1:
        break;

        default:
        ExecuteRotation(balance_factor, curr, data);
        break;
    }

    return curr;
}

bool AVLTree::Remove(const int& data) {

    const int old_count = this->node_count;

    this->root = RemoveHelper(this->root, data);

    return (old_count != this->node_count);
}

// NOT READABLE - REVIEW
AVLTree::TreeNode* AVLTree::RemoveHelper(TreeNode*& curr, const int& data) {

    if (curr == nullptr) {

        return curr;

    } else if (data == curr->getValue()) {

        if (curr->IsLeaf()) {
            
            delete curr;
            curr = nullptr;
            this->node_count--;
        } else if (curr->left_child == nullptr) {
           
            TreeNode* temp = curr;
            curr = curr->right_child;
            temp->right_child = nullptr;
            delete temp;
            this->node_count--;

        } else if (curr->right_child == nullptr) {
            
            TreeNode* temp = curr;
            curr = curr->left_child;
            temp->left_child = nullptr;
            delete temp;
            this->node_count--;
        } else {

            int replacement = 0;
            TreeNode* temp = curr->left_child;
            
            while (temp->right_child != nullptr) {
                
                temp = temp->right_child;
            }
            
            replacement = temp->getValue();
            curr->setValue(replacement);
            curr->left_child = RemoveHelper(curr->left_child, replacement);
        }

    } else if (data < curr->getValue()) {

        curr->left_child = RemoveHelper(curr->left_child, data);

    } else {

        curr->right_child = RemoveHelper(curr->right_child, data);
    } 

    curr->UpdateHeight();

    const int balance_factor = this->getBalanceFactor(curr);

    switch (balance_factor) {

        case 0:
        case -1:
        case 1:
        break;

        default:
        ExecuteRotation(balance_factor, curr, data);
        break;
    }

    return curr;
}

// Operator Overloads

// Prviate Member Functions
int AVLTree::getBalanceFactor(TreeNode*& node) {

    return (node == nullptr) ? 0 : node->left_child->getHeight() - node->right_child->getHeight();
}

void AVLTree::ExecuteRotation(const int bf, TreeNode*& curr, const int& val) {

    if (bf > 1 && val < curr->left_child->getValue()) {

        this->LeftLeftRotation(curr);
    } else if (bf < -1 && val > curr->right_child->getValue()) {

       this->RightRightRotation(curr);
    } else if (bf > 1 && val > curr->left_child->getValue()) {

        this->LeftRightRotation(curr);
    } else if (bf < -1 && val < curr->right_child->getValue()) {

        this->RightLeftRotation(curr);
    }
}

void AVLTree::LeftLeftRotation(TreeNode*& unbalanced) {

    TreeNode* lhs = unbalanced->left_child;
    unbalanced->left_child = lhs->right_child;
    lhs->right_child = unbalanced;
    unbalanced = lhs;

    unbalanced->right_child->UpdateHeight();
    unbalanced->UpdateHeight();
}

void AVLTree::RightRightRotation(TreeNode*& unbalanced) {

    TreeNode* rhs = unbalanced->right_child;
    unbalanced->right_child = rhs->left_child;
    rhs->left_child = unbalanced;
    unbalanced = rhs;

    unbalanced->left_child->UpdateHeight();
    unbalanced->UpdateHeight();
}

void AVLTree::RightLeftRotation(TreeNode*& unbalanced) {

    this->LeftLeftRotation(unbalanced->right_child);
    this->RightRightRotation(unbalanced);
}

void AVLTree::LeftRightRotation(TreeNode*& unbalanced) {

    this->RightRightRotation(unbalanced->left_child);
    this->LeftLeftRotation(unbalanced);
}