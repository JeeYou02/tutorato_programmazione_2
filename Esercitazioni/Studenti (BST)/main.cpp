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

    s = b.search(1004);
    cout << *s << endl;

    cout << b;

    b.deleteNode(1003);
    b.deleteNode(1005);

    cout << b;

}
