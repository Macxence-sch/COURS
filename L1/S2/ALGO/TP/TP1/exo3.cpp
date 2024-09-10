#include <iostream>
#include <vector>
#include <set>

using namespace std;

void afficher_valeurs_manquantes(const vector<vector<int>>& matrice, int max) {
    for (int i = 0; i < matrice.size(); ++i) {
        set<int> valeurs;
        for (int j = 0; j < matrice[i].size(); ++j) {
            if (matrice[i][j] != 0) {
                valeurs.insert(matrice[i][j]);
            }
        }
        cout << "Ligne " << i + 1 << " sera pour max=" << max << " : {";
        for (int k = 1; k <= max; ++k) {
            if (valeurs.find(k) == valeurs.end()) {
                cout << k;
                if (k != max) {
                    cout << ", ";
                }
            }
        }
        cout << "}\n";
    }
}

int main() {
    int max;
    cout << "Entrez la valeur de max : ";
    cin >> max;

    int m, n;
    cout << "Entrez le nombre de lignes de la matrice : ";
    cin >> m;
    cout << "Entrez le nombre de colonnes de la matrice : ";
    cin >> n;

    vector<vector<int>> matrice(m, vector<int>(n));

    cout << "Entrez les éléments de la matrice ligne par ligne : \n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrice[i][j];
        }
    }

    afficher_valeurs_manquantes(matrice, max);

    return 0;
}
