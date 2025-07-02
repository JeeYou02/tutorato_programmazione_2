#ifndef NODE_H
#define NODE_H

#include <iostream>

class BST;

template <class T>
class Node{
    private:
    T val;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    public:
    Node(T _val, Node<T>* _parent = NULL, Node<T>* _left = NULL, Node<T>* _right = NULL): val(_val), parent(_parent), left(_left), right(_right){}

    T getVal() { return val; }
    Node<T>* getParent() { return parent; }
    Node<T>* getLeft() { return left; }
    Node<T>* getRight() { return right; }

    void setVal(T _val) { val = _val; }
    void setParent(Node<T>* _parent) { parent = _parent; }
    void setLeft(Node<T>* _left) { left = _left; }
    void setRight(Node<T>* _right) { right = _right; }

    bool isLeftChild() { return this == this->parent->left; }
    bool isRightChild() { return this == this->parent->right; }

    friend class BST;
};

#endif