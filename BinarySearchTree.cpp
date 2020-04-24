//
// Created by grzesiek on 13.04.2020.
//
#define COUNT 10

#include "BinarySearchTree.h"
#include<cmath>
#include<iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() {
    right = NULL;
    parent = NULL;
    left = NULL;
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    root = NULL;
}

void BinarySearchTree::addKey(int value) {
    if (root == NULL) {
        root = new node(value, NULL, NULL, NULL);
    } else {
        node *tempNode = root;
        while (tempNode != NULL) {
            if (tempNode->value >= value) {
                if (tempNode->left == NULL) {
                    node *y = new node(value, NULL, NULL, tempNode);
                    tempNode->left = y;
                    tempNode = NULL;
                } else
                    tempNode = tempNode->left;
            } else {
                if (tempNode->right == NULL) {
                    node *y = new node(value, NULL, NULL, tempNode);
                    tempNode->right = y;
                    tempNode = NULL;
                } else
                    tempNode = tempNode->right;
            }
        }
    }
}

void BinarySearchTree::removeKey(int value) {
    node *tempNode = root;
    while (tempNode != NULL && tempNode->value != value) {
        if (tempNode->value > value) {
            tempNode = tempNode->left;
        } else if (tempNode->value <= value) {
            tempNode = tempNode->right;
        }
        if (tempNode->value == value) {

            if (tempNode->right == NULL && tempNode->left == NULL) {
                if (tempNode->parent != NULL && tempNode->parent->value >= value) {
                    tempNode->parent->left = NULL;
                } else if (tempNode->parent != NULL && tempNode->parent->value < value) {
                    tempNode->parent->right = NULL;
                }
            } else if (tempNode->left == NULL) {
                tempNode->parent->right = tempNode->right;
            } else if (tempNode->left != NULL && tempNode->right == NULL) {
                tempNode->parent->left = tempNode->left;
            } else if (tempNode->left != NULL && tempNode->right != NULL) {
                if (tempNode->left->right == NULL) {
                    if (tempNode->parent->value >= value) {
                        tempNode->parent->left = new node(tempNode->left->value, tempNode->left->left, tempNode->right,
                                                          tempNode->parent);
                    } else
                        tempNode->parent->right = new node(tempNode->left->value, tempNode->left->left, tempNode->right,
                                                           tempNode->parent);
                } else {
                    node *maxOfLeftSubTree = tempNode->left;
                    while (maxOfLeftSubTree->right != NULL) {
                        maxOfLeftSubTree = maxOfLeftSubTree->right;
                    }
                    if (tempNode->parent->value >= value) {
                        tempNode->parent->left = new node(maxOfLeftSubTree->value, tempNode->left,
                                                          tempNode->right,
                                                          tempNode->parent);
                    } else
                        tempNode->parent->right = new node(maxOfLeftSubTree->value, tempNode->left,
                                                           tempNode->right,
                                                           tempNode->parent);
                    maxOfLeftSubTree->parent->right = NULL;
                }
            }
        }
    }
}

void BinarySearchTree::balanceTree() {
// first phase of dsw algorithm
    node *tempNode = root;
    while (tempNode != NULL) {
        if (tempNode->left != NULL) {
            int temp = tempNode->value;
            tempNode->changeValue(tempNode->left->value);
            node *tempNode2 = tempNode->left;
            tempNode->left->changeValue(temp);
            tempNode->left = tempNode->left->left;
            tempNode2->left = tempNode2->right;
            tempNode2->right = tempNode->right;
            tempNode->right = tempNode2;
        } else
            tempNode = tempNode->right;
    }
    //second phase of algorithm
    int nodeCount = 0;
    tempNode = root;
    while (tempNode != NULL) {
        nodeCount++;
        tempNode = tempNode->right;
    }
    tempNode = root;
    int numOfFirstRotations = nodeCount + 1 - floor(pow(2, floor(log2(nodeCount + 1))));
    for (int i = 0; i < numOfFirstRotations; i++) {
        if (i == 0) {
            root->left = new node(tempNode->right->value, NULL, NULL, root);
            root->right = tempNode->right->right;
            tempNode = root->right;
        } else {
            int tempValue = tempNode->value;
            tempNode->left = new node(tempValue, NULL, NULL, tempNode);
            tempNode->changeValue(tempNode->right->value);
            tempNode->right = tempNode->right->right;
            tempNode = tempNode->right;
        }
    }
    int secondNumRotationCounter = nodeCount - numOfFirstRotations;
    tempNode = root;
    while (secondNumRotationCounter > 1) {
        secondNumRotationCounter = floor(secondNumRotationCounter / 2);
        for (int i = 0; i < secondNumRotationCounter; i++) {
            if (i == 0) {
                //todo bo nie dziala 
            }
        }
        tempNode = root;
    }


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
