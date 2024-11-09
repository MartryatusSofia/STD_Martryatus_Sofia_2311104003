#include <iostream>
#include <cstring>
using namespace std;

struct mahasiswa{
    char nama[30];
    char nim[10];
};

struct Node {
    mahasiswa data;
    Node * next;
};

Node *head;
Node *tail;

void init(){
    head = nullptr;
    tail = nullptr;
}

bool isEmpty(){
    return head == nullptr;
}

void insertDepan(const mahasiswa &data){
    Node *baru = new Node;
    baru->data = data;
    baru->next = nullptr;
    if (isEmpty()){
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(const mahasiswa &data){
    Node *baru = new Node;
    baru->data = data;
    baru->next = nullptr;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList() {
    Node *current = head;
    int jumlah = 0;
    while (current != nullptr) {
        jumlah++;
        current = current->next;
    }
    return jumlah;
}

void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        if (head == nullptr) {
            tail = nullptr; // Jika list menjadi kosong
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr; // List menjadi kosong
        } else {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = nullptr;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}



