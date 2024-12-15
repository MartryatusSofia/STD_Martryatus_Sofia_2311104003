#include <iostream>
#include <string>

using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList {
    Kendaraan info;
    ElmList* next;
    ElmList* prev;
};

struct List {
    ElmList* first;
    ElmList* last;
};

void CreateList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

ElmList* alokasi(Kendaraan x) {
    ElmList* newElm = new ElmList;
    newElm->info = x;
    newElm->next = nullptr;
    newElm->prev = nullptr;
    return newElm;
}

void dealokasi(ElmList* &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    ElmList* current = L.first;
    int i = 1;
    while (current != nullptr) {
        cout << "DATA LIST " << i++ << endl;
        cout << "No Polisi : " << current->info.nopol << endl;
        cout << "Warna     : " << current->info.warna << endl;
        cout << "Tahun     : " << current->info.thnBuat << endl;
        current = current->next;
    }
}

void insertLast(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirst(List &L, ElmList* &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        P->next = nullptr;
    }
}

void deleteLast(List &L, ElmList* &P) {
    if (L.last != nullptr) {
        P = L.last;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

void deleteAfter(ElmList* Prec, ElmList* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

// Fungsi untuk mencari elemen berdasarkan nomor polisi
ElmList* findElm(const List &L, const string &nopol) {
    ElmList* current = L.first;
    while (current != nullptr) {
        if (current->info.nopol == nopol) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Prosedur untuk menghapus elemen berdasarkan nomor polisi
void deleteByNopol(List &L, const string &nopol) {
    ElmList* P = findElm(L, nopol);

    if (P == nullptr) {
        cout << "\nData dengan nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "\nData dengan nomor polisi " << nopol << " berhasil dihapus.\n";
        dealokasi(P);
    }
}

int main() {
    List L;
    CreateList(L);
    
    int jumlahData;
    cout << "Masukkan jumlah data kendaraan: ";
    cin >> jumlahData;
    cin.ignore();

    for (int i = 0; i < jumlahData; ++i) {
        Kendaraan k;
        
        cout << "\nMasukkan nomor polisi  : ";
        getline(cin, k.nopol);
        cout << "Masukkan warna         : ";
        getline(cin, k.warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> k.thnBuat;
        cin.ignore();  // Mengabaikan karakter newline setelah cin
        
        ElmList* P = alokasi(k);
        insertLast(L, P);
    }
    
    cout << "\nData kendaraan yang dimasukkan:\n";
    printInfo(L);

    // Pengguna memasukkan nomor polisi yang ingin dihapus
    string nopol;
    cout << "\nMasukkan nomor polisi yang ingin dihapus: ";
    getline(cin, nopol);
    deleteByNopol(L, nopol);

    cout << "\nData kendaraan yang tersisa:\n";
    printInfo(L);

    // Dealokasi semua elemen untuk menghindari kebocoran memori
    ElmList* current = L.first;
    while (current != nullptr) {
        ElmList* temp = current;
        current = current->next;
        dealokasi(temp);
    }

    return 0;
}
