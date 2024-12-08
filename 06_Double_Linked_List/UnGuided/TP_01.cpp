#include <iostream>

using namespace std;

// Struktur Node untuk menyimpan data elemen
struct Node {
    int data;
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

// Alokasi node baru dengan data elemen
Node* alokasi(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Menambahkan elemen di awal linked list
void insertFirst(List &L, int data) {
    Node* newNode = alokasi(data);
    if (L.first == nullptr) { // Jika list kosong
        L.first = newNode;
        L.last = newNode;
    } else { // Jika list tidak kosong
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

// Menambahkan elemen di akhir linked list
void insertLast(List &L, int data) {
    Node* newNode = alokasi(data);
    if (L.first == nullptr) { // Jika list kosong
        L.first = newNode;
        L.last = newNode;
    } else { // Jika list tidak kosong
        newNode->prev = L.last;
        L.last->next = newNode;
        L.last = newNode;
    }
}

// Menampilkan semua elemen dari depan ke belakang
void printForward(const List &L) {
    Node* current = L.first;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);

    // Input dan penambahan elemen sesuai instruksi soal
    int data;
    
    cout << "Masukkan elemen pertama = ";
    cin >> data;
    insertLast(L, data);  // Menambahkan elemen pertama di akhir (atau awal karena list kosong)
    
    cout << "Masukkan elemen kedua di awal = ";
    cin >> data;
    insertFirst(L, data);  // Menambahkan elemen kedua di awal

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> data;
    insertLast(L, data);  // Menambahkan elemen ketiga di akhir

    // Tampilkan list dari depan ke belakang
    printForward(L);

    return 0;
}
