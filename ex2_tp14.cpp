
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Exception personnalisee
class StockInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : stock insuffisant !";
    }
};

// Classe Produit
class Produit {
private:
    string nom;
    int stock;

public:
    // Constructeur
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    // Methode vendre
    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException();
        }

        if (quantite <= 0) {
            throw invalid_argument("Quantite invalide !");
        }

        stock -= quantite;

        cout << "Vente reussie !" << endl;
        cout << "Stock restant : " << stock << endl;
    }
};

int main() {
    Produit p("Ordinateur", 10);

    try {
        p.vendre(3);
        p.vendre(5);
        p.vendre(4);
    }
    catch (const StockInsuffisantException& e) {
        cout << e.what() << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
