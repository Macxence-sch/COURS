#include <iostream>

using namespace std;

// Fonction récursive pour obtenir le miroir d'une chaîne de caractères
string miroir(const string& str, int index) {
    if (index < 0) {
        return "";
    } else {
        return str[index] + miroir(str, index - 1);
    }
}

// Fonction récursive pour dupliquer chaque valeur du vecteur
void dupliquerMiroir(string* vecteur, int taille, int index) {
    if (index < taille) {
        string element = vecteur[index];
        string elementMiroir = miroir(element, element.size() - 1);
        for (int i = taille; i > index; i--) {
            vecteur[i] = vecteur[i - 1];
        }
        vecteur[index + 1] = elementMiroir;
        dupliquerMiroir(vecteur, taille + 1, index + 2); // On saute le nouvel élément inséré
    }
}

int main() {
    // Vecteur initial
    string vecteur[] = {"information"};
    int taille = 1;

    // Dupliquer le miroir de chaque élément
    dupliquerMiroir(vecteur, taille, 0);

    // Afficher le vecteur résultant
    for (int i = 0; i < taille; i++) {
        cout << vecteur[i];
    }
    cout << endl;

    return 0;
}