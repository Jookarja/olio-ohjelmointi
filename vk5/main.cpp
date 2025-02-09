#include <iostream>
#include <string>

using namespace std;

class Seuraaja {
public:
    string nimi;
    Seuraaja* next;

    Seuraaja(string n) : nimi(n), next(nullptr) {}
    void paivitys(const string& viesti) {
        cout << nimi << " sai viestin: " << viesti << endl;
    }
};

class Notifikaattori {
private:
    Seuraaja* alku;

public:
    Notifikaattori() : alku(nullptr) {}

    void lisaa(string nimi) {
        Seuraaja* uusi = new Seuraaja(nimi);
        uusi->next = alku;
        alku = uusi;
    }

    void poista(string nimi) {
        Seuraaja* nykyinen = alku;
        Seuraaja* edellinen = nullptr;

        while (nykyinen != nullptr) {
            if (nykyinen->nimi == nimi) {
                if (edellinen == nullptr) {
                    alku = nykyinen->next;
                } else {
                    edellinen->next = nykyinen->next;
                }
                delete nykyinen;
                return;
            }
            edellinen = nykyinen;
            nykyinen = nykyinen->next;
        }
    }

    void tulosta() {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            cout << nykyinen->nimi << endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(string viesti) {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }

    ~Notifikaattori() {
        while (alku != nullptr) {
            Seuraaja* poistettava = alku;
            alku = alku->next;
            delete poistettava;
        }
    }
};

int main() {
    Notifikaattori n;
    n.lisaa("Alice");
    n.lisaa("Bob");
    n.lisaa("Charlie");

    cout << "Seuraajat:" << endl;
    n.tulosta();

    cout << "\nLähetetään viesti..." << endl;
    n.postita("Uusi päivitys saatavilla!");

    cout << "\nPoistetaan Bob..." << endl;
    n.poista("Bob");
    n.tulosta();

    return 0;
}
