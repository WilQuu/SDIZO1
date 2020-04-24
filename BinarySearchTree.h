//
// Created by grzesiek on 13.04.2020.
//

#ifndef UNTITLED_BINARYSEARCHTREE_H
#define UNTITLED_BINARYSEARCHTREE_H

struct node {
    node *left;
    node *right;
    node *parent;
    int value;

    node(int value, node *left, node *right, node *parent) {
        this->left = left;
        this->right = right;
        this->parent = parent;
        this->value = value;
    }
    void changeValue(int value){
        this->value=value;
    }
};

class BinarySearchTree {
private:
    node *left;
    node *right;
    node *parent;
public:
    node *root;
    BinarySearchTree();

    ~BinarySearchTree();

    void addKey(int value);

    void removeKey(int value);

    void balanceTree();

    void print2DUtil(node *root, int space);

    void print2D(node* root);
};


#endif //UNTITLED_BINARYSEARCHTREE_H

