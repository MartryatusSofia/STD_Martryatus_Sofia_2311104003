#include <iostream>
using namespace std;

// Struktur untuk node dalam Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Kelas untuk Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan elemen di akhir list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {  // Jika list kosong
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next) {  // Menemukan node terakhir
            last = last->next;
        }

        last->next = newNode;  // Menghubungkan node baru
        newNode->prev = last;  // Mengatur prev untuk node baru
    }

    // Fungsi untuk menampilkan elemen dari depan ke belakang
    void displayForward() {
        Node* current = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menampilkan elemen dari belakang ke depan
    void displayBackward() {
        Node* current = head;
        if (!current) return;

        // Menemukan node terakhir
        while (current->next) {
            current = current->next;
        }

        cout << "Daftar elemen dari belakang ke depan: ";
        while (current) {
            cout << current->data;
            if (current->prev) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }
};

// Fungsi utama
int main() {
    DoublyLinkedList dll;

    // Input dari pengguna
    cout << "Masukkan 4 elemen secara berurutan:" << endl;
    for (int i = 0; i < 4; ++i) {
        int element;
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        cin >> element;
        dll.append(element);  // Menambahkan elemen ke dalam list
    }

    // Menampilkan elemen
    dll.displayForward();   // Tampilkan dari depan ke belakang
    dll.displayBackward();  // Tampilkan dari belakang ke depan

    return 0;
}
