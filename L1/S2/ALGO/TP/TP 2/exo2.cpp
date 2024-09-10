#include <iostream>

using namespace std;

// Sous-programme récursif pour insérer une valeur dans un vecteur entre deux indices
void Rec_Inser(int val, int* vect, int Iinf, int Isup) {
    if (Iinf > Isup) {
        // Cas de base : aucun élément à insérer, donc on termine la récursion
        return;
    }

    if (Iinf == Isup) {
        // Cas de base : un seul élément entre les indices, on insère val à la bonne position
        if (val < vect[Iinf]) {
            // Insérer val avant vect[Iinf]
            int temp = vect[Iinf];
            vect[Iinf] = val;
            vect[Iinf + 1] = temp;
        } else {
            // Insérer val après vect[Iinf]
            vect[Isup + 1] = val;
        }
    } else {
        // Cas récursif : il y a plus d'un élément entre les indices
        int milieu = (Iinf + Isup) / 2; // Trouver l'indice du milieu
        if (val < vect[milieu]) {
            // Insérer dans la moitié gauche du vecteur
            Rec_Inser(val, vect, Iinf, milieu);
        } else {
            // Insérer dans la moitié droite du vecteur
            Rec_Inser(val, vect, milieu + 1, Isup);
        }
    }
}

int main() {
    const int taille = 7;
    int vecteur[taille] = {1, 3, 5, 7, 9, 11, 13}; // Vecteur trié
    int val = 6; // Valeur à insérer

    // Affichage du vecteur avant insertion
    cout << "Vecteur avant insertion : ";
    for (int i = 0; i < taille; ++i) {
        cout << vecteur[i] << " ";
    }
    cout << endl;

    // Insertion de la valeur dans le vecteur
    Rec_Inser(val, vecteur, 0, taille - 1);

    // Affichage du vecteur après insertion
    cout << "Vecteur après insertion : ";
    for (int i = 0; i < taille + 1; ++i) {
        cout << vecteur[i] << " ";
    }
    cout << endl;

    return 0;
}
