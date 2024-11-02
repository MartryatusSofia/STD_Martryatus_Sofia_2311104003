#include <iostream>
using namespace std;

int main() {
    int n, pilihan;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    
    int arr[n], total = 0;
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i]; 
    }

    do {
        cout << "\nMenu:\n1. Nilai Maksimum\n2. Nilai Minimum\n3. Nilai Rata-rata\n4. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int maks = arr[0];
            for (int i = 1; i < n; i++) if (arr[i] > maks) maks = arr[i];
            cout << "Nilai Maksimum: " << maks << endl;
        }
        else if (pilihan == 2) {
            int min = arr[0];
            for (int i = 1; i < n; i++) if (arr[i] < min) min = arr[i];
            cout << "Nilai Minimum: " << min << endl;
        }
        else if (pilihan == 3) {
            cout << "Nilai Rata-rata: " << (double)total / n << endl;
        }
    } while (pilihan != 4);

    return 0;
}
