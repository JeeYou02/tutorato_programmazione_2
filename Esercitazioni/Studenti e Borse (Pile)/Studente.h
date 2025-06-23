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
    virtual ~Studente(){}

    inline int getMatricola() const { return matricola; }
    inline string getNome() const { return nome; }
    inline string getCognome() const { return cognome; }
    inline float getMedia() const { return media; }

    virtual int get_importo_borsa() const { return 0; }

    virtual void stampa(ostream& os) const {
        os << matricola << ": " << nome << " " << cognome << " - media " << media << endl;
    }

};

class BorsaDiStudio{
    private:
    int importo;
    int durata;

    public:
    BorsaDiStudio(int _importo, int _durata): importo(_importo), durata(_durata){}

    inline int getImporto() const { return importo; }
    inline int getDurata() const { return durata; }

    void setImporto(int _importo) { importo = _importo; }
    void setDurata(int _durata) { durata = _durata; }
};

class StudenteBorsista: public Studente{
    private:
    BorsaDiStudio* borsa;

    public:
    StudenteBorsista(int _matricola, string _nome, string _cognome, float _media, BorsaDiStudio* _borsa = NULL): Studente(_matricola, _nome, _cognome, _media), borsa(_borsa) {}
    ~StudenteBorsista(){ delete borsa; }

    int get_importo_borsa() const { return borsa->getImporto(); }

    void stampa(ostream& os) const {
        os << this->getMatricola() << ": " << this->getNome() << " " << this->getCognome() << " - media " << this->getMedia() << " [borsa di " << get_importo_borsa() << " euro]" << endl;
    }
};

ostream& operator<<(ostream& os, const Studente* s){
    s->stampa(os);
    return os;
}

#endif