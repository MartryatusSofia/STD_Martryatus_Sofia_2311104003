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

// Menghapus elemen pertama dari linked list
void deleteFirst(List &L) {
    if (L.first != nullptr) { // Jika list tidak kosong
        Node* temp = L.first;
        if (L.first == L.last) { // Jika hanya ada satu elemen
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        delete temp;
    } else {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    }
}

// Menghapus elemen terakhir dari linked list
void deleteLast(List &L) {
    if (L.last != nullptr) { // Jika list tidak kosong
        Node* temp = L.last;
        if (L.first == L.last) { // Jika hanya ada satu elemen
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        delete temp;
    } else {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    }
}

// Menampilkan semua elemen dari depan ke belakang
void printForward(const List &L) {
    Node* current = L.first;
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    if (current == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
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
    
    cout << "Masukkan elemen kedua di akhir = ";
    cin >> data;
    insertLast(L, data);  // Menambahkan elemen kedua di akhir

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> data;
    insertLast(L, data);  // Menambahkan elemen ketiga di akhir

    // Hapus elemen pertama dan terakhir
    deleteFirst(L);
    deleteLast(L);

    // Tampilkan list setelah penghapusan
    printForward(L);

    return 0;
}
