#ifndef PILA_H
#define PILA_H

#include <iostream>

#include "Node.h"

using namespace std;

template <class T>
class Pila{
    private:
    Node<T>* head;

    public:
    Pila(Node<T>* _head = NULL): head(_head){}
    ~Pila(){ while(!isEmpty()) pop(); }

    bool isEmpty() { return head == NULL; }

    void push(T val){
        Node<T>* new_node = new Node<T>(val);
        
        if(isEmpty()){
            head = new_node;
            return;
        }
        
        new_node->next = head;
        head = new_node;
    }

    T pop(){
        if(isEmpty())
            return NULL;
        
        Node<T>* toDelete = head;
        head = head->next;

        T toReturn = toDelete->val;

        delete toDelete;
        return toReturn;
    }

    void stampa(ostream& os){
        Node<T>* curr = head;

        while(curr){
            os << curr->val;
            curr = curr->next;
        }
    }

};

template <class T>
ostream& operator<<(ostream& os, Pila<T>& p){
    p.stampa(os);
    return os;
}

#endif