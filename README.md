
# 🧮 Classes Abstraites et Interfaces

## 📘 Description

Ce document regroupe plusieurs projets C++ illustrant l’usage du polymorphisme, des classes abstraites, et des structures dynamiques pour modéliser des comportements variés :

- Calculs géométriques via héritage abstrait

- Comportements animaux polymorphes

- Systèmes de paiement dynamiques

- Arborescence de fichiers avec composition récursive

## 📂 Project Structure
````
projets/
├── FormesGeometriques/
│   └── FormesGeometriques.cpp
├── GestionAnimaux/
│   └── GestionAnimaux.cpp
├── InterfacePaiement/
│   └── InterfacePaiement.cpp
├── SystemeFichiersVirtuel/
│   └── SystemeFichiersVirtuel.cpp
└── README.md
````


## ⚙️ Features

### **1.** FormesGeometriques – Calcul d’aires via polymorphisme
Classe abstraite Forme :

- Méthode virtuelle pure double aire() const : Interface pour le calcul d’aire des formes géométriques.

Classe Cercle dérivée de Forme :

- Attribut privé rayon

- Constructeur Cercle(double) : initialise le rayon

- Méthode aire() : retourne l’aire du cercle via la formule π·r²

Classe Rectangle dérivée de Forme :

- Attributs privés longeur, largeur

- Constructeur Rectangle(double, double) : initialise les dimensions

- Méthode aire() : retourne l’aire du rectangle via la formule l·L

Fonction main() :

- Création dynamique d’un tableau de pointeurs Forme*

- Saisie interactive des formes et de leurs dimensions

- Affichage des aires calculées

- Libération de la mémoire


### **2.** GestionAnimaux – Comportements vocaux polymorphes
Classe abstraite Animal :

- Méthode virtuelle pure void crier() const : Interface pour le cri de l’animal

- Méthode concrète info() : affiche une phrase générique

Classes dérivées Chien, Chat, Vache : Redéfinissent crier() avec leur propre son :

- Chien → "Wouf!"

- Chat → "Miaou!"

- Vache → "Meuh!"

Fonction main()
- Utilisation d’un vector<unique_ptr<Animal>>

- Ajout de plusieurs animaux

- Appel polymorphe des méthodes info() et crier()

- Gestion automatique de la mémoire via unique_ptr

### **3.** InterfacePaiement – Traitement polymorphe des transactions
Classe abstraite Paiement :
- Méthode virtuelle pure void effectuerPaiement(double) : Interface pour exécuter un paiement

Classe PaiementCarte dérivée de Paiement :
- Redéfinit effectuerPaiement() : affiche un message de paiement par carte

Classe PaiementEspece dérivée de Paiement :
- Redéfinit effectuerPaiement() : affiche un message de paiement en espèces

Fonction main()
- Création dynamique d’un tableau de Paiement*

- Choix du type de paiement pour chaque transaction

- Saisie du montant et exécution polymorphe

- Affichage des messages correspondants

### **4.** SystemeFichiersVirtuel – Arborescence récursive de fichiers
Classe abstraite NoeudFichier :
Méthodes virtuelles pures :

- string nom() const

- int taille() const

Classe Fichier dérivée de NoeudFichier :
- Attributs privés nomF, tailleF

- Constructeur Fichier(string, int) : initialise nom et taille

- Méthodes nom() et taille() : retournent les valeurs correspondantes

Classe Dossier dérivée de NoeudFichier :
- Attribut privé nomD

- Vecteur vector<unique_ptr<NoeudFichier>> fichiers

- Constructeur Dossier(string) : initialise le nom

- Méthode ajouter(unique_ptr<NoeudFichier>) : ajoute un fichier ou dossier

- Méthode taille() : somme récursive des tailles

- Méthode afficher(int) : affiche l’arborescence avec indentation

Fonction main() :
- Création d’un dossier racine

- Ajout de fichiers et sous-dossiers

- Affichage récursif de la structure

- Calcul de la taille totale
## 🖥️ Example Execution


###  Formes géométriques :

### Interface de paiement : 

###  Gestion d’animaux :

### Système de fichiers virtuel :

## 💡 Concepts Practiced

- Polymorphisme via classes abstraites et méthodes virtuelles

- Allocation dynamique avec new, unique_ptr et vector

- Composition récursive pour modéliser des structures hiérarchiques

- Encapsulation et séparation des responsabilités par classe

## 🧑‍💻 Author

- 👤 Agouram Hassan
- 🏫 Programmation orientée objet : C++
- 🎓 Instructor	Mr.LACHGAR
- 📅 31	October 2025
