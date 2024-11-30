#include "stack.h"
#include <iostream>
using namespace std;

// Inisialisasi stack kosong
void createStack(stack &S) {
    S.Top = 0;
}

// Mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.Top == 0;
}

// Mengecek apakah stack penuh
bool isFull(stack S) {
    return S.Top == 15;
}

// Menambahkan elemen ke dalam stack
void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top - 1] = x;
    } else {
        cout << "Stack penuh, tidak bisa menambah elemen.\n";
    }
}

// Mengambil elemen dari stack
int pop (stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.Top - 1];
        S.Top--;
        return x;
    } else {
        cout << "Stack kosong, tidak ada elemen untuk diambil.\n";
        return '\0'; // Mengembalikan karakter null jika kosong
    }
}


// Menampilkan semua elemen dalam stack
void printInfo(stack S) {
    if (!isEmpty(S)) {
        for (int i = S.Top - 1; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong.\n";
    }
}
