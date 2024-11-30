#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    // Inisialisasi pelajaran
    string namapel = "Struktur Data";
    string kodepel = "STD";

    // Membuat pelajaran
    Pelajaran pel = create_pelajaran(namapel, kodepel);

    // Menampilkan pelajaran
    tampil_pelajaran(pel);

    return 0;
}
