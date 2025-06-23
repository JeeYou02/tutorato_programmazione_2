#ifndef NODE_H
#define NODE_H

#include "Pila.h"

template <class T>
class Pila;

template <class T>
class Node{
    private:
    T val;
    Node<T>* next;

    public:
    Node(T _val, Node<T>* _next = NULL): val(_val), next(_next){}

    T getVal() const { return val; }
    Node<T>* getNext() const { return next; }

    void setVal(T _val) { this->val = _val; }
    void setNext(Node<T>* _next) { this->next = _next; }

    friend class Pila<T>;
};

#endif