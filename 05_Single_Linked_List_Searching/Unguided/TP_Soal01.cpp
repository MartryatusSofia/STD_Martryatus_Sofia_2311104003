#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L) {
    L.head = nullptr;
}

void insertLast(List &L, int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    
    if (L.head == nullptr) {
        L.head = newNode;
    } else {
        Node* current = L.head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void searchElement(const List &L, int target) {
    Node* current = L.head;
    int position = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->info == target) {
            cout << "Elemen " << target << " ditemukan pada alamat " << current 
                 << " di urutan ke-" << position << "." << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Elemen " << target << " tidak ditemukan dalam list." << endl;
    }
}

int main() {
    List L;
    createList(L);

    cout << "Masukkan 6 elemen integer untuk dimasukkan ke dalam list:" << endl;
    for (int i = 0; i < 6; i++) {
        int value;
        cout << "Elemen " << i + 1 << ": ";
        cin >> value;
        insertLast(L, value);
    }

    int target;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    searchElement(L, target);

    return 0;
}
