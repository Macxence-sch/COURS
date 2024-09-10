#include <iostream>

using namespace std;

// Sous-programme récursif pour trier un sous-vecteur en utilisant Rec_Inser
void Rec_Tri_ins(int* vect, int N, int Iinf) {
    if (Iinf <= N) {
        // Trier le sous-vecteur entre 1 et Iinf-1 en utilisant Rec_Inser
        Rec_Inser(vect[Iinf], vect, 1, Iinf - 1);
        // Trier le sous-vecteur entre Iinf+1 et N
        Rec_Tri_ins(vect, N, Iinf + 1);
    }
}

// Fonction récursive pour insérer une valeur dans un vecteur entre deux indices
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
    int vecteur[taille] = {13, 5, 7, 9, 3, 11, 1}; // Vecteur non trié

    // Affichage du vecteur avant le tri
    cout << "Vecteur avant le tri : ";
    for (int i = 0; i < taille; ++i) {
        cout << vecteur[i] << " ";
    }
    cout << endl;

    // Tri récursif du vecteur
    Rec_Tri_ins(vecteur, taille - 1, 1);

    // Affichage du vecteur après le tri
    cout << "Vecteur après le tri : ";
    for (int i = 0; i < taille; ++i) {
        cout << vecteur[i] << " ";
    }
    cout << endl;

    return 0;
}
