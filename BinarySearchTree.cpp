//
// Created by grzesiek on 13.04.2020.
//
#define COUNT 10
#include<bits/stdc++.h>

#include "BinarySearchTree.h"
#include<iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() {
    right = NULL;
    parent = NULL;
    left = NULL;
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    root=NULL;
}

void BinarySearchTree::addKey(int value) {
    if (root == NULL) {
        root = new node(value, NULL, NULL, NULL);
    } else {
        node *x = NULL;
        x = root;
        while (x != NULL) {
            if (x->value < value) {
                x = x->left;
                if (x == NULL) {
                    node *y = new node(value, NULL, NULL, x->parent);
                }
            } else {
                x = x->right;
                if (x == NULL) {
                    node *y = new node(value, NULL, NULL, x->parent);
                }
            }
        }
        balanceTree();
    }
}

void BinarySearchTree::balanceTree() {

}

void BinarySearchTree::print2DUtil(node *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->value << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

void BinarySearchTree::print2D(node *root) {
    // Pass initial space count as 0
    print2DUtil(root, 0);
}