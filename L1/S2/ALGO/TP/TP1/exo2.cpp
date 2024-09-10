#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void crible_eratosthene(int n) {
    // Créer un vecteur pour marquer les nombres
    vector<bool> est_premier(n + 1, true);

    // Le 0 et le 1 ne sont pas premiers
    est_premier[0] = est_premier[1] = false;

    // Marquer les multiples comme non premiers
    for (int i = 2; i <= sqrt(n); ++i) {
        if (est_premier[i]) {
            for (int j = i * i; j <= n; j += i) {
                est_premier[j] = false;
            }
        }
    }

    // Afficher les nombres premiers
    cout << "Les nombres premiers jusqu'a " << n << " sont : ";
    for (int i = 2; i <= n; ++i) {
        if (est_premier[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Entrez la valeur de n : ";
    cin >> n;

    crible_eratosthene(n);

    return 0;
}
