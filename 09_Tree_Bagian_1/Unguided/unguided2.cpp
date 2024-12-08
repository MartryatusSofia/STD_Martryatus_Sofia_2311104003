#include <iostream>
#include <limits.h> // Untuk batas nilai min dan max
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

// Fungsi Rekursif untuk Memeriksa Apakah Pohon adalah BST
bool is_valid_bst(Pohon *node, int min_val, int max_val) {
    if (!node) return true; // Basis rekursi: node kosong selalu valid
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && // Periksa subtree kiri
           is_valid_bst(node->right, node->data, max_val);  // Periksa subtree kanan
}

// Fungsi untuk Pengujian
void uji_is_valid_bst() {
    // Membuat Pohon Valid BST
    Pohon *root1 = buatNode(10);
    root1->left = buatNode(5);
    root1->right = buatNode(15);
    root1->left->left = buatNode(3);
    root1->left->right = buatNode(7);
    root1->right->left = buatNode(12);
    root1->right->right = buatNode(18);

    // Membuat Pohon Tidak Valid BST
    Pohon *root2 = buatNode(10);
    root2->left = buatNode(15); // Invalid: 15 > 10 (di subtree kiri)
    root2->right = buatNode(5); // Invalid: 5 < 10 (di subtree kanan)

    // Pengujian pada Pohon Valid
    cout << "Pohon 1 (Valid BST): " << (is_valid_bst(root1, INT_MIN, INT_MAX) ? "Ya" : "Tidak") << endl;

    // Pengujian pada Pohon Tidak Valid
    cout << "Pohon 2 (Tidak Valid BST): " << (is_valid_bst(root2, INT_MIN, INT_MAX) ? "Ya" : "Tidak") << endl;
}

// Fungsi utama
int main() {
    uji_is_valid_bst();
    return 0;
}
