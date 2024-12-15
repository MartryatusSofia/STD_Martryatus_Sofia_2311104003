#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Kota {
    string nama;
    vector<int> jarak;
};

int main() {
    int jumlahKota;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahKota;

    vector<Kota> kota(jumlahKota);

    for (int i = 0; i < jumlahKota; ++i) {
        cout << "Masukkan nama simpul " << i+1 << ": ";
        cin >> kota[i].nama;
        kota[i].jarak.resize(jumlahKota); 
    }

    cout << "Masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlahKota; ++i) {
        for (int j = 0; j < jumlahKota; ++j) {
            cout << kota[i].nama << " --> " << kota[j].nama << " = ";
            cin >> kota[i].jarak[j];
        }
    }

    for (int i = 0; i < jumlahKota; ++i) {
        cout << "\t" << kota[i].nama;
    }
    cout << endl;
    for (int i = 0; i < jumlahKota; ++i) {
        cout << kota[i].nama;
        for (int j = 0; j < jumlahKota; ++j) {
            cout << "\t" << kota[i].jarak[j];
        }
        cout << endl;
    }

    return 0;
}