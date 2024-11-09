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

void printList(const List &L) {
    Node* current = L.head;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

void insertSorted(List &L, int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    if (L.head == nullptr || L.head->info >= value) {
        newNode->next = L.head;
        L.head = newNode;
    } else {
        Node* current = L.head;
        Node* prev = nullptr;

        while (current != nullptr && current->info < value) {
            prev = current;
            current = current->next;
        }

        prev->next = newNode;
        newNode->next = current;
    }
}

int main() {
    List L;
    createList(L);

    cout << "Masukkan 4 elemen integer untuk dimasukkan ke dalam list:" << endl;
    for (int i = 0; i < 4; i++) {
        int value;
        cout << "Elemen " << i + 1 << ": ";
        cin >> value;
        insertSorted(L, value);  
    }

    cout << "\nList setelah 4 elemen dimasukkan: ";
    printList(L);

    int newValue;
    cout << "\nMasukkan elemen tambahan yang ingin ditambahkan secara terurut: ";
    cin >> newValue;
    insertSorted(L, newValue);
    
    cout << "\nList setelah elemen tambahan dimasukkan: ";
    printList(L);

    return 0;
}
