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

void bubbleSortList(List &L) {
    bool swapped;
    do {
        swapped = false;
        Node* current = L.head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->info > current->next->info) {
                // Tukar data antar node
                int temp = current->info;
                current->info = current->next->info;
                current->next->info = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped); 
}

int main() {
    List L;
    createList(L);

    cout << "Masukkan 5 elemen integer untuk dimasukkan ke dalam list:" << endl;
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Elemen " << i + 1 << ": ";
        cin >> value;
        insertLast(L, value);
    }

    cout << "\nList sebelum diurutkan: ";
    printList(L);

    bubbleSortList(L);

    cout << "List setelah diurutkan: ";
    printList(L);

    return 0;
}
