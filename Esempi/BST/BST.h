#ifndef BST_H
#define BST_H

#include "node.h"

template <class T>
class BST{
    private:
    Node<T>* root;

    Node<T>* minimo(Node<T>* n){
        while(n->left)
            n = n->left;

        return n;
    }

    public:
    BST(Node<T>* _root = NULL): root(_root){}
    ~BST() { destroy(root); }

    void destroy(Node<T>* n){
        if(n){
            destroy(n->left);
            destroy(n->right);
            delete n;
        }
    }

    void insert(const Studente& s){
        Studente* stud = new Studente(s);
        Node<T>* new_node = new Node<T>(stud);

        if(root == NULL){
            root = new_node;
            return;
        }

        Node<T>* curr = root;
        Node<T>* prec = NULL;
        while(curr){
            prec = curr;
            if(new_node->val->getMatricola() > curr->val->getMatricola())
                curr = curr->right;
            else
                curr = curr->left;
        }

        if(new_node->val->getMatricola() > prec->val->getMatricola())
            prec->right = new_node;
        else
            prec->left = new_node;
        new_node->parent = prec;
    }

    Node<T>* search(int matricola){
        if(root == NULL) return NULL;

        Node<T>* curr = root;
        while(curr && (curr->val->getMatricola() != matricola)){
            if(matricola > curr->val->getMatricola())
                curr = curr->right;
            else
                curr = curr->left;
        }

        //return (curr == NULL)? NULL : curr->val;
        return curr;
    }

    void deleteNode(Node<T>* n){
        /*if(!n->left && !n->right){    //il nodo è una foglia
            if(n->isLeftChild())
                n->parent->left = NULL;
            else
                n->parent->right = NULL;
            
            delete n;
            return;
        }*/

        if(!n->left){     //il nodo non ha il figlio sinistro (foglia o solo figlio destro)
            if(!n->parent)
                root = n->right;
            else if(n->isLeftChild())
                n->parent->left = n->right;
            else
                n->parent->right = n->right;
            
            if(n->right)
                n->right->parent = n->parent;

            delete n;
            return;
        }

        else if(!n->right){     //il nodo ha un solo figlio (sinistro)
            if(!n->parent)
                root = n->left;
            else if(n->isLeftChild())
                n->parent->left = n->left;
            else
                n->parent->right = n->left;
            
            n->left->parent = n->parent;

            delete n;
            return;
        }

        else{
            Node<T>* succ = minimo(n->right);      //minimo del sottoalbero destro
            n->val = succ->val;
            deleteNode(succ);
        }
    }

    void inOrder(ostream& os, Node<T>* n){
        if(n){
            inOrder(os, n->left);
            os << *(n->val);
            inOrder(os, n->right);
        }
    }

    void stampa(ostream& os){ inOrder(os, root); }
};

#endif