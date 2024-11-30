#include "singlelist.h"

int main() {
    List L;
    createList(L);

    address P1 = alokasi(2);
    insertFirst(L, P1);

    address P2 = alokasi(0);
    insertFirst(L, P2);

    address P3 = alokasi(8);
    insertFirst(L, P3);

    address P4 = alokasi(12);
    insertFirst(L, P4);

    address P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L); 

    address found = findElm(L, 8);
    if (found != nullptr) {
        cout << "Elemen dengan info 8 ditemukan: " << found->info << endl;
    } else {
        cout << "Elemen dengan info 8 tidak ditemukan" << endl;
    }

    int total = sumInfo(L);
    cout << "Jumlah total info seluruh elemen: " << total << endl; // Output: 31

    return 0;
}
