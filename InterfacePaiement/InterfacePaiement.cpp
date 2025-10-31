#include <iostream>
using namespace std;

class Paiement
{
public:
    virtual void effectuerPaiement(double montant) = 0;
};

class PaiementCarte : public Paiement
{
public:
    void effectuerPaiement(double montant) override
    {
        cout << "Paiement de " << montant << " DH par carte bancaire." << endl;
    }
};

class PaiementEspece : public Paiement
{
public:
    void effectuerPaiement(double montant) override
    {
        cout << "Paiement de " << montant << " DH en especes." << endl;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cout << "Donner la taille de tableau : ";
    cin >> n;

    Paiement **tab = new Paiement *[n];

    for (size_t i = 0; i < size_t(n); i++)
    {
        int choix;
        cout << "==== Paiment ====" << endl;
        cout << "_1_ Paiement par Carte bancaire" << endl;
        cout << "_2_ Paiement especes" << endl;
        cin >> choix;

        switch (choix)
        {
        case 1:
            tab[i] = new PaiementCarte;
            break;
        case 2:
            tab[i] = new PaiementEspece;
            break;
        default:
            tab[i] = nullptr;
        }
    }

    for (size_t i = 0; i < size_t(n); i++)
    {
        double montant;
        cout << "Le montant de paiment: ";
        cin >> montant;
        if (tab[i] != nullptr)
        {
            cout << "Paiment " << i + 1 << " : " << endl;
            tab[i]->effectuerPaiement(montant);
        }
    }

    return 0;
}
