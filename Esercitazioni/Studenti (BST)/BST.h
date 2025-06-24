#ifndef BST_H
#define BST_H

#include "node.h"

class BST{
    private:
    Node* root;

    Node* minimo(Node* n){
        while(n->left)
            n = n->left;

        return n;
    }

    bool del(Node* n){
        if(!n->left && !n->right){   //foglia
            if(n == n->parent->left)
                n->parent->left = n->right;
            else
                n->parent->right = NULL;
            
            delete n;
            return true;
        }

        else if(!n->left || !n->right){   //un figlio
            if(n == n->parent->left){     //è figlio sinistro
                if(n->left){             //ha figlio sinistro
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                    delete n;
                    return true;
                } else {
                    n->parent->left = n->right;
                    n->right->parent = n->parent;
                    delete n;
                    return true;
                }
            } else {                        //è figlio destro
                if(n->left){
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                    delete n;
                    return true;
                } else{
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                    delete n;
                    return true;
                }
            }
        }
        return false;
    }

    public:
    BST(Node* _root = NULL): root(_root){}
    ~BST() { destroy(root); }

    void destroy(Node* n){
        if(n){
            destroy(n->left);
            destroy(n->right);
            delete n;
        }
    }

    void insert(const Studente& s){
        Studente* stud = new Studente(s);
        Node* new_node = new Node(stud);

        if(root == NULL){
            root = new_node;
            return;
        }

        Node* curr = root;
        Node* prec = NULL;
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

    Studente* search(int matricola){
        if(root == NULL) return NULL;

        Node* curr = root;
        while(curr && (curr->val->getMatricola() != matricola)){
            if(matricola > curr->val->getMatricola())
                curr = curr->right;
            else
                curr = curr->left;
        }

        return (curr == NULL)? NULL : curr->val;
    }

    void deleteNode(int matricola){
        if(root == NULL) return;

        Node* curr = root;
        while(curr && (curr->val->getMatricola() != matricola)){
            if(matricola > curr->val->getMatricola())
                curr = curr->right;
            else
                curr = curr->left;
        }
        if(!curr) return;

        if(del(curr)) return;
        
        Node* succ = minimo(curr->right);
        Studente* aux = curr->val;
        curr->val = succ->val;
        succ->val = aux;

        del(succ);
    }

    void inOrder(ostream& os, Node* n){
        if(n){
            inOrder(os, n->left);
            os << *(n->val);
            inOrder(os, n->right);
        }
    }

    void stampa(ostream& os){ inOrder(os, root); }
};

ostream& operator<<(ostream& os, BST& b){
    b.stampa(os);
    return os;
}

#endif