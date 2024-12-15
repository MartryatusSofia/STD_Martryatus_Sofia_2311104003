#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    stack S;
    createStack(S);

    // Digit terakhir NIM MOD 4 sisa 3, maka output "S T R U K T U R D A T A"
    char data[] = {'S', 'T', 'R', 'U', 'K', 'T', 'U', 'R', ' ', 'D', 'A', 'T', 'A'};
    
    // Push semua karakter ke dalam stack
    for (char c : data) {
        push(S, c);
    }
    
    // Tampilkan isi stack awal
    cout << "Isi stack awal: ";
    printInfo(S);

    // Pop 8 kali untuk menyisakan "D A T A" saja
    for (int i = 0; i < 8; i++) {
        pop(S);
    }

    // Tampilkan isi stack setelah pop
    cout << "Isi stack setelah pop: ";
    printInfo(S);

    return 0;
}
