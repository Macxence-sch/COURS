#include <iostream>

using namespace std;

// Fonction d'échange pour échanger deux éléments d'un tableau
void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fonction partition pour partitionner le tableau autour de l'élément pivot
int partitionner(int* tableau, int debut, int fin) {
    int pivot = tableau[fin]; // Choix du pivot comme dernier élément
    int i = debut - 1; // Indice du plus petit élément

    for (int j = debut; j < fin; j++) {
        if (tableau[j] < pivot) {
            i++;
            echanger(tableau[i], tableau[j]);
        }
    }
    echanger(tableau[i + 1], tableau[fin]);
    return i + 1;
}

// Fonction de tri rapide (Quicksort)
void quicksort(int* tableau, int debut, int fin) {
    if (debut < fin) {
        int pivotIndex = partitionner(tableau, debut, fin);
        quicksort(tableau, debut, pivotIndex - 1); // Trier la partie gauche du pivot
        quicksort(tableau, pivotIndex + 1, fin);   // Trier la partie droite du pivot
    }
}

int main() {
    int tableau[] = {12, 5, 3, 8, 9, 7, 1, 4, 6, 2};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    cout << "Tableau avant le tri rapide : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    quicksort(tableau, 0, taille - 1);

    cout << "Tableau après le tri rapide : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    return 0;
}
