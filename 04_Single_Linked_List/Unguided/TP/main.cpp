#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List L;
    createList(L);

    address P;
    int nim[10] = {2, 3, 1, 1, 1, 0, 4, 0, 0, 3};
    
    for (int i = 0; i < 10; i++) {
        P = allocate(nim[i]);
        if (P != NULL) {
            insertLast(L, P);
            cout << "Elemen berhasil ditambahkan: " << info(P) << endl;
            cout << "Isi List: ";
            printInfo(L);
        } else {
            cout << "Gagal mengalokasikan memori untuk elemen " << nim[i] << endl;
        }
    }

    return 0;
}
