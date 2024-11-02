#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    int NIM;
    string nama;
    Mahasiswa* next;
};

struct List {
    Mahasiswa* first;
};


void createList(List &L) {
    L.first = nullptr;
}

Mahasiswa* alokasi(int NIM, const string& nama) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->NIM = NIM;
    newNode->nama = nama;
    newNode->next = nullptr;
    return newNode;
}


void insertFirst(List &L, int NIM, const string& nama) {
    Mahasiswa* newNode = alokasi(NIM, nama);
    newNode->next = L.first;
    L.first = newNode;
    cout << "Mahasiswa dengan NIM " << NIM << " dan nama " << nama << " telah ditambahkan." << endl;
}

Mahasiswa* findMahasiswa(const List &L, int NIM) {
    Mahasiswa* current = L.first;
    while (current != nullptr) {
        if (current->NIM == NIM) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void searchMahasiswa(const List &L, int NIM) {
    Mahasiswa* result = findMahasiswa(L, NIM);
    if (result != nullptr) {
        cout << "Mahasiswa ditemukan: Nama = " << result->nama << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }
}

int main() {
    List L;
    createList(L);

    insertFirst(L, 2311104001, "Melani");
    insertFirst(L, 2311104002, "Shilfi");
    insertFirst(L, 2311104003, "Sopie");

    searchMahasiswa(L, 2311104002); 
    searchMahasiswa(L, 2311104005); 

    return 0;
}
