#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Deklarasi fungsi
void init();
bool isEmpty();
void buatNode(char data);
Pohon *insertLeft(char data, Pohon *node);
Pohon *insertRight(char data, Pohon *node);
void lihatChild(Pohon *node);
void lihatDescendant(Pohon *node);
Pohon *findNode(Pohon *node, char data);
bool is_valid_bst(Pohon *node, char min_val, char max_val);
int cari_simpul_daun(Pohon *node);
void menu();

// Inisialisasi pohon
void init() {
    root = NULL;
}

// Cek apakah pohon kosong
bool isEmpty() {
    return root == NULL;
}

// Buat node baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah child kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah child kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Cari node berdasarkan data
Pohon *findNode(Pohon *node, char data) {
    if (!node) return NULL;
    if (node->data == data) return node;
    Pohon *found = findNode(node->left, data);
    if (found) return found;
    return findNode(node->right, data);
}

// Lihat child dari suatu node
void lihatChild(Pohon *node) {
    if (isEmpty() || !node) {
        cout << "\nNode tidak ada atau pohon kosong." << endl;
        return;
    }
    cout << "\nChild dari node " << node->data << ": ";
    if (node->left) cout << "Left = " << node->left->data << " ";
    if (node->right) cout << "Right = " << node->right->data << " ";
    if (!node->left && !node->right) cout << "(tidak ada)";
    cout << endl;
}

// Lihat semua descendant dari suatu node
void lihatDescendant(Pohon *node) {
    if (!node) return;
    if (node->left) cout << node->left->data << " ";
    if (node->right) cout << node->right->data << " ";
    lihatDescendant(node->left);
    lihatDescendant(node->right);
}

// Periksa apakah pohon adalah BST
bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Hitung jumlah simpul daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Fungsi menu utama
void menu() {
    int pilihan;
    char data, parent;
    Pohon *node;

    do {
        cout << "\n=== MENU TREE ===";
        cout << "\n1. Buat Root";
        cout << "\n2. Tambah Node Kiri";
        cout << "\n3. Tambah Node Kanan";
        cout << "\n4. Lihat Child";
        cout << "\n5. Lihat Descendant";
        cout << "\n6. Periksa BST";
        cout << "\n7. Hitung Simpul Daun";
        cout << "\n8. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (!isEmpty()) {
                    cout << "\nPohon sudah dibuat!" << endl;
                } else {
                    cout << "Masukkan data root: ";
                    cin >> data;
                    buatNode(data);
                }
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parent;
                cout << "Masukkan data node baru: ";
                cin >> data;
                node = findNode(root, parent);
                if (node) insertLeft(data, node);
                else cout << "\nParent tidak ditemukan!" << endl;
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parent;
                cout << "Masukkan data node baru: ";
                cin >> data;
                node = findNode(root, parent);
                if (node) insertRight(data, node);
                else cout << "\nParent tidak ditemukan!" << endl;
                break;
            case 4:
                cout << "Masukkan data node: ";
                cin >> data;
                node = findNode(root, data);
                lihatChild(node);
                break;
            case 5:
                cout << "Masukkan data node: ";
                cin >> data;
                node = findNode(root, data);
                if (!node) {
                    cout << "\nNode tidak ditemukan!" << endl;
                } else {
                    cout << "\nDescendant dari " << node->data << ": ";
                    lihatDescendant(node);
                    cout << endl;
                }
                break;
            case 6:
                if (is_valid_bst(root, '0', 'z')) {
                    cout << "\nPohon adalah Binary Search Tree (BST)." << endl;
                } else {
                    cout << "\nPohon bukan Binary Search Tree (BST)." << endl;
                }
                break;
            case 7:
                cout << "\nJumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case 8:
                cout << "\nKeluar dari program." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid." << endl;
        }
    } while (pilihan != 8);
}

// Fungsi utama
int main() {
    init();
    menu();
    return 0;
}
