#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
#include <string>

using namespace std;

class Studente{
    private:
    int matricola;
    string nome;
    string cognome;
    float media;

    public:
    Studente(int _matricola, string _nome, string _cognome, float _media){
        matricola = _matricola;
        nome = _nome;
        cognome = _cognome;
        media = _media;
    }
    Studente(const Studente& s){
        matricola = s.matricola;
        nome= s.nome;
        cognome = s.cognome;
        media = s.media;
    }

    int getMatricola() { return matricola; }
    string getNome() { return nome; }
    string getCognome() { return cognome; }
    float getMedia() { return media; }

    void stampa(ostream& os){
        os << matricola << ": " << nome << " " << cognome << " - media " << media << endl;
    }
};

ostream& operator<<(ostream& os, Studente& s){
    s.stampa(os);
    return os;
}

#endif