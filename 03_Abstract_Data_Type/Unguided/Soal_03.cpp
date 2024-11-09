#include <iostream>
using namespace std;

int main() {
    int x = 25;     
    int* ptr;      

    ptr = &x;      
  
    cout << "Nilai dari x: " << x << endl;
    cout << "Alamat memori dari x (disimpan dalam ptr): " << ptr << endl;

    cout << "Nilai yang ditunjuk oleh ptr: " << *ptr << endl;

    return 0;
}
