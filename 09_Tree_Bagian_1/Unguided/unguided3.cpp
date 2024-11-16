#include <iostream>
using namespace std;

// Deklarasi Struktur Node Pohon
struct Pohon {
    int data;
    Pohon *left, *right;
};

// Fungsi untuk Membuat Node Baru
Pohon *buatNode(int data) {
    return new Pohon{data, NULL, NULL};
}

// Fungsi Rekursif untuk Menghitung Simpul Daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0; // Basis rekursi: jika node kosong, jumlah daun adalah 0
    if (!node->left && !node->right) return 1; // Node tanpa anak kiri dan kanan adalah daun
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right); // Rekursi ke kiri dan kanan
}

// Fungsi untuk Pengujian
void uji_cari_simpul_daun() {
    // Membuat Binary Tree
    Pohon *root = buatNode(1);
    root->left = buatNode(2);
    root->right = buatNode(3);
    root->left->left = buatNode(4);
    root->left->right = buatNode(5);
    root->right->left = buatNode(6);

    // Menghitung Jumlah Simpul Daun
    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
}

// Fungsi utama
int main() {
    uji_cari_simpul_daun();
    return 0;
}
