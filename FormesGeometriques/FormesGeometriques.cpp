#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Forme
{
public:
    virtual double aire() const = 0;
};

class Cercle : public Forme
{
private:
    double rayon;

public:
    Cercle(double r) : rayon(r) {}

    double aire() const override
    {
        return M_PI * pow(rayon, 2);
    }
};

class Rectangle : public Forme
{
private:
    double longeur;
    double largeur;

public:
    Rectangle(double lo, double la) : longeur(lo), largeur(la) {}

    double aire() const override
    {
        return longeur * largeur;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cout << "donner la taille de tebleau";
    cin >> n;
    cin.ignore();

    Forme **tab = new Forme *[n];

    for (size_t i = 0; i < size_t(n); i++)
    {
        int choix;
        cout << "Forme (" << i + 1 << ") :" << endl;
        cout << "-1- Cercle :" << endl;
        cout << "-2- Rectangle :" << endl;
        cin >> choix;
        cin.ignore();

        switch (choix)
        {
        case 1:
            double r;
            cout << "Donner le rayon de cercle : ";
            cin >> r;
            tab[i] = new Cercle(r);
            break;
        case 2:
            double lo;
            double la;
            cout << "Donner le longeur de rectangle : ";
            cin >> lo;
            cout << "Donner la largeur de rectangle : ";
            cin >> la;
            tab[i] = new Rectangle(lo, la);
            break;
        default:
            tab[i] = nullptr;
            break;
        }
    }

    for (size_t i = 0; i < size_t(n); i++)
    {
        if (tab[i] != nullptr)
        {
            cout << "L'aire de Forme " << i + 1 << " : " << tab[i]->aire() << endl;
        }
    }

    for (size_t i = 0; i < size_t(n); i++)
    {
        delete[] tab[i];
    }

    delete[] tab;

    return 0;
}
