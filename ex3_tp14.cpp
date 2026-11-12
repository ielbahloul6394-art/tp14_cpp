
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Fonction de lecture du fichier
void lireFichier(string nomFichier) {
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ouvrir le fichier !");
    }

    string ligne;

    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

int main() {
    try {
        lireFichier("test.txt");
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
