
#include <iostream>
#include <exception>
using namespace std;

// Exception pour montant invalide
class MontantInvalideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : montant invalide !";
    }
};

// Exception pour solde insuffisant
class SoldeInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : solde insuffisant !";
    }
};

// Classe Compte
class Compte {
private:
    int solde;

public:
    // Constructeur
    Compte(int s) {
        solde = s;
    }

    // Methode deposer
    void deposer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        solde += montant;
        cout << "Depot reussi : " << montant << endl;
        cout << "Solde actuel : " << solde << endl;
    }

    // Methode retirer
    void retirer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        if (montant > solde) {
            throw SoldeInsuffisantException();
        }

        solde -= montant;
        cout << "Retrait reussi : " << montant << endl;
        cout << "Solde actuel : " << solde << endl;
    }
};

int main() {
    Compte c(1000);

    // Premier test
    try {
        c.deposer(500);
        c.retirer(200);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    // Deuxieme test
    try {
        c.deposer(-100);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    // Troisieme test
    try {
        c.retirer(2000);
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
