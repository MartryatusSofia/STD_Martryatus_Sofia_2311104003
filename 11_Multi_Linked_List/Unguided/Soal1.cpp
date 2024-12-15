#include <iostream>
#include <string>
using namespace std;

// Struktur untuk data proyek
struct ProyekNode {
    string namaProyek;
    int durasi; // Durasi dalam bulan
    ProyekNode* next;

    ProyekNode(string nama, int durasiProyek) : namaProyek(nama), durasi(durasiProyek), next(nullptr) {}
};

struct PegawaiNode {
    string namaPegawai, idPegawai;
    ProyekNode* proyek;
    PegawaiNode* next;

    PegawaiNode(string nama, string id) : namaPegawai(nama), idPegawai(id), proyek(nullptr), next(nullptr) {}
};

class ManajemenPegawai {
private:
    PegawaiNode* head;

public:
    ManajemenPegawai() : head(nullptr) {}

    void tambahPegawai(string nama, string id) {
        PegawaiNode* pegawaiBaru = new PegawaiNode(nama, id);
        if (!head) {
            head = pegawaiBaru;
        } else {
            PegawaiNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = pegawaiBaru;
        }
    }

    void tambahProyek(string idPegawai, string namaProyek, int durasi) {
        PegawaiNode* pegawai = head;
        while (pegawai) {
            if (pegawai->idPegawai == idPegawai) {
                ProyekNode* proyekBaru = new ProyekNode(namaProyek, durasi);
                if (!pegawai->proyek) {
                    pegawai->proyek = proyekBaru;
                } else {
                    ProyekNode* temp = pegawai->proyek;
                    while (temp->next) {
                        temp = temp->next;
                    }
                    temp->next = proyekBaru;
                }
                return;
            }
            pegawai = pegawai->next;
        }
    }

    void hapusProyek(string idPegawai, string namaProyek) {
        PegawaiNode* pegawai = head;
        while (pegawai) {
            if (pegawai->idPegawai == idPegawai) {
                ProyekNode* proyek = pegawai->proyek;
                ProyekNode* prev = nullptr;
                while (proyek) {
                    if (proyek->namaProyek == namaProyek) {
                        if (prev) {
                            prev->next = proyek->next;
                        } else {
                            pegawai->proyek = proyek->next;
                        }
                        delete proyek;
                        return;
                    }
                    prev = proyek;
                    proyek = proyek->next;
                }
            }
            pegawai = pegawai->next;
        }
    }

    void tampilkanData() {
        PegawaiNode* pegawai = head;
        while (pegawai) {
            cout << "Pegawai: " << pegawai->namaPegawai << ", ID: " << pegawai->idPegawai << endl;
            ProyekNode* proyek = pegawai->proyek;
            while (proyek) {
                cout << "  Proyek: " << proyek->namaProyek << ", Durasi: " << proyek->durasi << " bulan" << endl;
                proyek = proyek->next;
            }
            pegawai = pegawai->next;
        }
    }
};

int main() {
    ManajemenPegawai manajemen;

    manajemen.tambahPegawai("Andi", "P001");
    manajemen.tambahPegawai("Budi", "P002");
    manajemen.tambahPegawai("Citra", "P003");

    manajemen.tambahProyek("P001", "Aplikasi Mobile", 12);
    manajemen.tambahProyek("P002", "Sistem Akuntansi", 8);
    manajemen.tambahProyek("P003", "E-commerce", 10);

    manajemen.tambahProyek("P001", "Analisis Data", 6);

    manajemen.hapusProyek("P001", "Aplikasi Mobile");

    manajemen.tampilkanData();

    return 0;
}
