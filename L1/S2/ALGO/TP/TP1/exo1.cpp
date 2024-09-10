#include <iostream>
#include <vector>

using namespace std;

// Fonction pour trier le vecteur par insertion
void tri_insertion(vector<int> &vecteur) {
    int n = vecteur.size();
    for (int i = 1; i < n; ++i) {
        int cle = vecteur[i];
        int j = i - 1;

        // Déplacer les éléments du vecteur [0..i-1] qui sont plus grands que la clé
        // vers une position avant leur position actuelle
        while (j >= 0 && vecteur[j] > cle) {
            vecteur[j + 1] = vecteur[j];
            j = j - 1;
        }
        vecteur[j + 1] = cle;
    }
}

// Fonction pour afficher le contenu du vecteur
void afficher_vecteur(const vector<int> &vecteur) {
    for (int i = 0; i < vecteur.size(); ++i) {
        cout << vecteur[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> mon_vecteur = {12, 5, 9, 3, 7};

    cout << "Vecteur avant le tri par insertion : ";
    afficher_vecteur(mon_vecteur);

    tri_insertion(mon_vecteur);

    cout << "Vecteur après le tri par insertion : ";
    afficher_vecteur(mon_vecteur);

    return 0;
}
