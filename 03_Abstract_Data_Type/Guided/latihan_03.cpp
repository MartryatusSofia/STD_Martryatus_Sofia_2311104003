#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarArray(int arr1[3][3], int arr2[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        int temp = arr1[row][col];
        arr1[row][col] = arr2[row][col];
        arr2[row][col] = temp;
    } else {
        cout << "Indeks di luar batas array!" << endl;
    }
}

void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "Array 1 sebelum pertukaran:" << endl;
    tampilkanArray(array1);
    
    cout << "Array 2 sebelum pertukaran:" << endl;
    tampilkanArray(array2);

    cout << "Menukar elemen di posisi (1, 1):" << endl;
    tukarArray(array1, array2, 1, 1);
    
    cout << "Array 1 setelah pertukaran:" << endl;
    tampilkanArray(array1);
    
    cout << "Array 2 setelah pertukaran:" << endl;
    tampilkanArray(array2);

    cout << "\nNilai sebelum pertukaran pointer:" << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Nilai setelah pertukaran pointer:" << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;

    return 0;
}
