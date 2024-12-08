#include <iostream>
#include <string>
using namespace std;

struct BukuNode {
    string judulBuku;
    string tanggalPengembalian;
    BukuNode* next;

    BukuNode(string judul, string tanggal) : judulBuku(judul), tanggalPengembalian(tanggal), next(nullptr) {}
};

struct AnggotaNode {
    string namaAnggota, idAnggota;
    BukuNode* buku;
    AnggotaNode* next;

    AnggotaNode(string nama, string id) : namaAnggota(nama), idAnggota(id), buku(nullptr), next(nullptr) {}
};

class ManajemenPerpustakaan {
private:
    AnggotaNode* head;

public:
    ManajemenPerpustakaan() : head(nullptr) {}

    void tambahAnggota(string nama, string id) {
        AnggotaNode* anggotaBaru = new AnggotaNode(nama, id);
        if (!head) {
            head = anggotaBaru;
        } else {
            AnggotaNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = anggotaBaru;
        }
    }

    void tambahBuku(string idAnggota, string judul, string tanggal) {
        AnggotaNode* anggota = head;
        while (anggota) {
            if (anggota->idAnggota == idAnggota) {
                BukuNode* bukuBaru = new BukuNode(judul, tanggal);
                if (!anggota->buku) {
                    anggota->buku = bukuBaru;
                } else {
                    BukuNode* temp = anggota->buku;
                    while (temp->next) {
                        temp = temp->next;
                    }
                    temp->next = bukuBaru;
                }
                return;
            }
            anggota = anggota->next;
        }
    }

    void hapusAnggota(string idAnggota) {
        AnggotaNode* anggota = head;
        AnggotaNode* prev = nullptr;

        while (anggota) {
            if (anggota->idAnggota == idAnggota) {
                if (prev) {
                    prev->next = anggota->next;
                } else {
                    head = anggota->next;
                }

                BukuNode* buku = anggota->buku;
                while (buku) {
                    BukuNode* temp = buku;
                    buku = buku->next;
                    delete temp;
                }
                delete anggota;
                return;
            }
            prev = anggota;
            anggota = anggota->next;
        }
    }

    void tampilkanData() {
        AnggotaNode* anggota = head;
        while (anggota) {
            cout << "Anggota: " << anggota->namaAnggota << ", ID: " << anggota->idAnggota << endl;
            BukuNode* buku = anggota->buku;
            while (buku) {
                cout << "  Buku: " << buku->judulBuku << ", Pengembalian: " << buku->tanggalPengembalian << endl;
                buku = buku->next;
            }
            anggota = anggota->next;
        }
    }
};

int main() {
    ManajemenPerpustakaan perpustakaan;

    perpustakaan.tambahAnggota("Rani", "A001");
    perpustakaan.tambahAnggota("Dito", "A002");
    perpustakaan.tambahAnggota("Vina", "A003");

    perpustakaan.tambahBuku("A001", "Pemrograman C++", "01/12/2024");
    perpustakaan.tambahBuku("A002", "Algoritma Pemrograman", "15/12/2024");

    perpustakaan.tambahBuku("A001", "Struktur Data", "10/12/2024");

    perpustakaan.hapusAnggota("A002");

    perpustakaan.tampilkanData();

    return 0;
}
