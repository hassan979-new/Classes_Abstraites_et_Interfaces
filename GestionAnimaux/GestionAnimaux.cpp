#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Animal
{
public:
    virtual void crier() const = 0;

    void info() const
    {
        cout << "Je suis un animal." << endl;
    }
};

class Chien : public Animal
{
public:
    void crier() const override
    {
        cout << "Wouf!" << endl;
    }
};

class Chat : public Animal
{
public:
    void crier() const override
    {
        cout << "Miaou!" << endl;
    }
};

class Vache : public Animal
{
public:
    void crier() const override
    {
        cout << "Meuh!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<unique_ptr<Animal>> animaux;

    animaux.push_back(make_unique<Chien>());
    animaux.push_back(make_unique<Chat>());
    animaux.push_back(make_unique<Vache>());

    for (size_t i = 0; i < size_t(animaux.size()); i++)
    {
        animaux[i]->info();
        animaux[i]->crier();
        cout << endl;
    }

    return 0;
}
