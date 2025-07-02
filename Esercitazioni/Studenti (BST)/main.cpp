#include <fstream>
#include <sstream>

#include "BST.h"

using namespace std;

int main(){
    ifstream in("input.txt");

    BST b;
    Studente* s;

    string line;
    string str;
    int matricola; string nome; string cognome; float media;
    while(in >> line){
        stringstream ss(line);
        getline(ss, str, ',');
        matricola = stoi(str);
        getline(ss, nome, ',');
        getline(ss, cognome, ',');
        getline(ss, str, ',');
        media = stof(str);

        s = new Studente(matricola, nome, cognome, media);
        b.insert(*s);
        delete s;
    }

    //s = b.search(1004);
    //cout << *s << endl;

    Node* n = b.search(1004);
    cout << *(n->getVal()) << endl;

    cout << b << endl;

    b.deleteNode(b.search(1002));
    b.deleteNode(b.search(1003));
    b.deleteNode(b.search(1006));

    cout << b;

}
