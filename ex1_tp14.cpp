
#include <iostream>
#include <stdexcept>
using namespace std;

// Fonction de division
double diviser(int a, int b) {
    if (b == 0) {
        throw runtime_error("Erreur : division par zero impossible !");
    }

    return (double)a / b;
}

int main() {
    try {
        cout << "10 / 2 = " << diviser(10, 2) << endl;
        cout << "15 / 3 = " << diviser(15, 3) << endl;
        cout << "8 / 0 = " << diviser(8, 0) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
