#include <iostream>
using namespace std;

void angkaKeTulisan(int angka) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan. Masukkan angka antara 0 dan 100." << endl;
        return;
    }

    if (angka < 12) 
        cout << satuan[angka];
    else if (angka < 20) 
        cout << satuan[angka - 10] << " belas";
    else if (angka < 100) 
        cout << puluhan[angka / 10] << (angka % 10 ? " " + satuan[angka % 10] : "");
    else 
        cout << "seratus";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;
    cout << "Dalam bentuk tulisan: ";
    angkaKeTulisan(angka);  // Memanggil fungsi untuk menampilkan angka dalam tulisan
    cout << endl; // Menambah baris baru setelah output
    return 0;
}
