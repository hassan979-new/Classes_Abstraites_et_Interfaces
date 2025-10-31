#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class NoeudFichier
{
public:
    virtual string nom() const = 0;

    virtual int taille() const = 0;
};

class Fichier : public NoeudFichier
{
private:
    string nomF;
    int tailleF;

public:
    Fichier(string n, int t) : nomF(n), tailleF(t) {}

    string nom() const override
    {
        return nomF;
    }

    int taille() const override
    {
        return tailleF;
    }
};

class Dossier : public NoeudFichier
{
private:
    string nomD;
    vector<unique_ptr<NoeudFichier>> fichiers;

public:
    Dossier(string n) : nomD(n) {}

    string nom() const override
    {
        return nomD;
    }

    void ajouter(unique_ptr<NoeudFichier> fichier)
    {
        fichiers.push_back(move(fichier));
    }

    int taille() const override
    {
        if (fichiers.empty())
        {
            return 0;
        }

        int taille = 0;
        for (const auto &a : fichiers)
        {
            taille += a->taille();
        }

        return taille;
    }

    void afficher(int niveau = 0) const
    {
        string indent(niveau * 2, ' ');
        cout << indent << "[Dossier] " << nomD << " (" << taille() << " Ko)" << endl;
        for (const auto &e : fichiers)
        {
            const Dossier *d = dynamic_cast<const Dossier *>(e.get());
            if (d)
                d->afficher(niveau + 1);
            else
                cout << indent << "  - " << e->nom() << " (" << e->taille() << " Ko)" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    auto racine = make_unique<Dossier>("Racine");

    racine->ajouter(make_unique<Fichier>("note.txt", 10));
    racine->ajouter(make_unique<Fichier>("image.jpg", 2000));

    auto documents = make_unique<Dossier>("Documents");
    documents->ajouter(make_unique<Fichier>("cv.pdf", 100));
    documents->ajouter(make_unique<Fichier>("rapport.docx", 300));

    racine->ajouter(move(documents));

    cout << "=== Structure du système de fichiers ===" << endl;
    racine->afficher();

    cout << "\nTaille totale du dossier Racine : " << racine->taille() << " Ko" << endl;

    return 0;
}
