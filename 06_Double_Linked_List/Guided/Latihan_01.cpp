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
        cin.ignore();  // Untuk mengabaikan karakter newline setelah cin
        
        ElmList* P = alokasi(k);
        insertLast(L, P);
    }
    
    cout << "\nData kendaraan yang dimasukkan:\n";
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
