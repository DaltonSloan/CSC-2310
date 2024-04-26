/*
    Title:    Lab8.cpp
    Author:   Dalton W. Sloan
    Date:     November 07, 2023
    Purpose:  Binary Search Tree.
*/

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST {
private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root; // The root of the binary search tree.

    // Recursive function to copy the structure of a tree.
    void copy(TreeNode*&, TreeNode*);
    
    // Recursive function to insert a node into the tree.
    void insert(TreeNode*&, TreeNode*);
    
    // Recursive function to display the tree in in-order traversal.
    void displayInOrder(TreeNode*) const;
    
    // Recursive function to destroy the entire subtree.
    void destroySubTree(TreeNode*);

public:
    BST() {
        root = nullptr; // Initialize an empty tree (constructor).
    }
    
    BST(const BST& tree) {
        root = nullptr; // Initialize a new tree, then copy the structure from the given tree (copy constructor).
        copy(root, tree.root);
    }
    
    ~BST() {
        destroySubTree(root); // Destructor to free all allocated memory.
    }

    // Function to insert a new node with a given value into the tree.
    void insertNode(int);

    // Function to display the tree in in-order traversal.
    void display() {
        displayInOrder(root);
    }
};

// Recursive function to insert a node into the binary search tree.
void BST::insert(TreeNode*& nodePtr, TreeNode* newNode) {
    if (nodePtr == nullptr) {
        nodePtr = newNode;
    } else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode); // If the value is less, go left.
    } else {
        insert(nodePtr->right, newNode); // If the value is greater or equal, go right.
    }
}

// Public function to insert a new node with a given value into the tree.
void BST::insertNode(int num) {
    TreeNode* newNode = new TreeNode;
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;
    insert(root, newNode);
}

// Recursive function to destroy the entire subtree.
void BST::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr) {
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }
        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr; // Free the memory of the current node.
    }
}

// Recursive function to display the tree in in-order traversal.
void BST::displayInOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left); // Traverse the left subtree.
        cout << nodePtr->value << " "; // Display the value of the current node.
        displayInOrder(nodePtr->right); // Traverse the right subtree.
    }
}

// Recursive function to copy the structure of a tree.
void BST::copy(TreeNode*& newTree, TreeNode* oTree) {
    if (oTree) {
        TreeNode* newNode = new TreeNode;
        newNode->value = oTree->value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        insert(newTree, newNode);
        copy(newTree, oTree->left);  // Copy the left subtree.
        copy(newTree, oTree->right); // Copy the right subtree.
    }
}

#endif
