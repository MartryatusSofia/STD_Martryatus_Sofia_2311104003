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

// Fungsi pencarian berdasarkan nomor polisi
void findByNopol(const List &L, const string &nopol) {
    ElmList* current = L.first;
    bool found = false;
    while (current != nullptr) {
        if (current->info.nopol == nopol) {
            cout << "\nData ditemukan:\n";
            cout << "No Polisi : " << current->info.nopol << endl;
            cout << "Warna     : " << current->info.warna << endl;
            cout << "Tahun     : " << current->info.thnBuat << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "\nData dengan nomor polisi " << nopol << " tidak ditemukan.\n";
    }
}

// Fungsi pencarian berdasarkan warna
void findByWarna(const List &L, const string &warna) {
    ElmList* current = L.first;
    bool found = false;
    while (current != nullptr) {
        if (current->info.warna == warna) {
            cout << "\nData ditemukan:\n";
            cout << "No Polisi : " << current->info.nopol << endl;
            cout << "Warna     : " << current->info.warna << endl;
            cout << "Tahun     : " << current->info.thnBuat << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "\nData dengan warna " << warna << " tidak ditemukan.\n";
    }
}

// Fungsi pencarian berdasarkan tahun pembuatan
void findByTahun(const List &L, int tahun) {
    ElmList* current = L.first;
    bool found = false;
    while (current != nullptr) {
        if (current->info.thnBuat == tahun) {
            cout << "\nData ditemukan:\n";
            cout << "No Polisi : " << current->info.nopol << endl;
            cout << "Warna     : " << current->info.warna << endl;
            cout << "Tahun     : " << current->info.thnBuat << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "\nData dengan tahun " << tahun << " tidak ditemukan.\n";
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

    // Menu pencarian
    int pilihan;
    do {
        cout << "\nPilih kriteria pencarian:\n";
        cout << "1. Cari berdasarkan Nomor Polisi\n";
        cout << "2. Cari berdasarkan Warna\n";
        cout << "3. Cari berdasarkan Tahun Pembuatan\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string nopol;
            cout << "Masukkan nomor polisi yang ingin dicari: ";
            getline(cin, nopol);
            findByNopol(L, nopol);
        } else if (pilihan == 2) {
            string warna;
            cout << "Masukkan warna yang ingin dicari: ";
            getline(cin, warna);
            findByWarna(L, warna);
        } else if (pilihan == 3) {
            int tahun;
            cout << "Masukkan tahun pembuatan yang ingin dicari: ";
            cin >> tahun;
            cin.ignore();
            findByTahun(L, tahun);
        } else if (pilihan == 4) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    // Dealokasi semua elemen untuk menghindari kebocoran memori
    ElmList* current = L.first;
    while (current != nullptr) {
        ElmList* temp = current;
        current = current->next;
        dealokasi(temp);
    }

    return 0;
}
