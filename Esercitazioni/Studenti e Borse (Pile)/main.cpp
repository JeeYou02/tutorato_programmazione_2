#include <fstream>

#include "Pila.h"
#include "Studente.h"

using namespace std;

int main(){
    fstream in("input.txt");

    Pila<Studente*> p1;
    int matricola; string nome; string cognome; float media; int importo; int durata;
    Studente* s;
    BorsaDiStudio* b;
    while(in >>  matricola >> nome >> cognome >> media >> importo >> durata){
        if(durata == 0)
            s = new Studente(matricola, nome, cognome, media);
        else{
            b = new BorsaDiStudio(importo, durata);
            s = new StudenteBorsista(matricola, nome, cognome, media, b);
        }
        p1.push(s);
    }

    Pila<Studente*> p2;
    int importo_tot = 0;
    while(!p1.isEmpty()){
        s = p1.pop();
        if(s->getMedia() < 25){
            cout << "Studente insufficiente rimosso: " << s->getNome() << " " << s->getCognome() << " - Matricola: " << s->getMatricola() << endl;
            delete s;
        }
        else{
            p2.push(s);
            importo_tot += s->get_importo_borsa();
        }
    }

    cout << p2;
    cout << endl << "Totale importi borse di studio: " << importo_tot << endl;
}
