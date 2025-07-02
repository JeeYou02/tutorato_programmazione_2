#ifndef NODE_H
#define NODE_H

#include "studente.h"

class BST;

class Node{
    private:
    Studente* val;
    Node* parent;
    Node* left;
    Node* right;

    public:
    Node(Studente* _val, Node* _parent = NULL, Node* _left = NULL, Node* _right = NULL): val(_val), parent(_parent), left(_left), right(_right){}

    Studente* getVal() { return val; }
    Node* getParent() { return parent; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setVal(Studente* _val) { val = _val; }
    void setParent(Node* _parent) { parent = _parent; }
    void setLeft(Node* _left) { left = _left; }
    void setRight(Node* _right) { right = _right; }

    bool isLeftChild() { return this == this->parent->left; }
    bool isRightChild() { return this == this->parent->right; }

    friend class BST;
};

#endif