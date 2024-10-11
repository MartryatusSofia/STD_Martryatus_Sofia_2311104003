#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah angka: ";
    cin >> n;

    cout << "Data Array: ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

    cout << "\nNomor Genap: ";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cout << i << ", ";
        }
    }

    cout << "\nNomor Ganjil: ";
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            cout << i << ", ";
        }
    }

    return 0;
}
