#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data buku
struct Buku {
    int id;
    string judul;
    string penulis;
};

struct Node {
    Buku info;
    Node* next;
    Node* prev;
};

// Struktur List untuk menyimpan pointer awal dan akhir
struct List {
    Node* first;
    Node* last;
};

// Membuat list kosong
void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

// Alokasi node baru dengan data buku
Node* alokasi(Buku buku) {
    Node* newNode = new Node;
    newNode->info = buku;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Menambah buku di akhir linked list
void insertLast(List &L, Node* newNode) {
    if (L.first == nullptr) { // Jika list kosong
        L.first = newNode;
        L.last = newNode;
    } else { // Jika list tidak kosong
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

// Menampilkan daftar buku dari awal ke akhir
void printForward(const List &L) {
    Node* current = L.first;
    int i = 1;
    cout << "Daftar Buku (dari awal ke akhir):\n";
    while (current != nullptr) {
        cout << "Buku " << i++ << ":\n";
        cout << "ID Buku   : " << current->info.id << endl;
        cout << "Judul     : " << current->info.judul << endl;
        cout << "Penulis   : " << current->info.penulis << endl;
        current = current->next;
    }
}

// Menampilkan daftar buku dari akhir ke awal
void printBackward(const List &L) {
    Node* current = L.last;
    int i = 1;
    cout << "Daftar Buku (dari akhir ke awal):\n";
    while (current != nullptr) {
        cout << "Buku " << i++ << ":\n";
        cout << "ID Buku   : " << current->info.id << endl;
        cout << "Judul     : " << current->info.judul << endl;
        cout << "Penulis   : " << current->info.penulis << endl;
        current = current->prev;
    }
}

int main() {
    List L;
    createList(L);

    int jumlahBuku;
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> jumlahBuku;
    cin.ignore();

    for (int i = 0; i < jumlahBuku; ++i) {
        Buku buku;
        cout << "\nMasukkan ID Buku   : ";
        cin >> buku.id;
        cin.ignore();
        cout << "Masukkan Judul Buku: ";
        getline(cin, buku.judul);
        cout << "Masukkan Penulis   : ";
        getline(cin, buku.penulis);

        Node* newNode = alokasi(buku);
        insertLast(L, newNode);
    }

    cout << "\n";
    printForward(L);
    cout << "\n";
    printBackward(L);

    return 0;
}
