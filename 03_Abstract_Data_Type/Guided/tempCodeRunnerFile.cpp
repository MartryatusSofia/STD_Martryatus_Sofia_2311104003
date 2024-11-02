#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Mahasiswa {
    string nama;
    char nim [10];
    float uts, uas, tugas, nilaiakhir;
    };

    float hitungNilaiAkhir(float uts, float uas, float tugas){
        return(0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
    }

    int main(){
        Mahasiswa mahasiswa[10];
        int jumlahMahasiswa;

        cout << "Masukkan jumlah mahasiswa (maks 10): ";
        cin >> jumlahMahasiswa;

        if (jumlahMahasiswa > 10) {
        cout << "Jumlah mahasiswa tidak boleh lebih dari 10!" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiakhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }
    cout << "\n\nData Mahasiswa dan Nilai Akhir:\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama       : " << mahasiswa[i].nama << endl;
        cout << "NIM        : " << mahasiswa[i].nim << endl;
        cout << "Nilai UTS  : " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS  : " << mahasiswa[i].uas << endl;
        cout << "Nilai Tugas: " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiakhir << endl;
    }
    return 0;
}