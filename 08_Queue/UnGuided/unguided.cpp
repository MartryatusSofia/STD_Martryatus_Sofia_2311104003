#include <iostream>
#include <string>

using namespace std;

struct MahasiswaNode {
    string nama;
    int nim;
    MahasiswaNode* next;
};

class PriorityQueue {
private:
    MahasiswaNode* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(string nama, int nim) {
        MahasiswaNode* new_node = new MahasiswaNode();
        new_node->nama = nama;
        new_node->nim = nim;
        new_node->next = nullptr;

        if (front == nullptr || nim < front->nim) {
            new_node->next = front;
            front = new_node;
        } else {
            MahasiswaNode* current = front;
            while (current->next != nullptr && current->next->nim <= nim) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Antrian kosong!" << endl;
        } else {
            MahasiswaNode* temp = front;
            cout << "Mahasiswa keluar dari antrian - NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Antrian kosong!" << endl;
        } else {
            MahasiswaNode* current = front;
            cout << "Antrian Mahasiswa berdasarkan prioritas NIM:" << endl;
            while (current != nullptr) {
                cout << "NIM: " << current->nim << ", Nama: " << current->nama << endl;
                current = current->next;
            }
        }
    }

    ~PriorityQueue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue queue;
    string nama;
    int nim;
    char lagi;

    cout << "Masukkan data mahasiswa" << endl;
    do {
        cout << "Nama: ";
        cin.ignore(); // Tambahkan ini setelah cin >> nim;
        getline(cin, nama); 
        cout << "NIM: ";
        cin >> nim;

        queue.enqueue(nama, nim);

        cout << "Tambah mahasiswa lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    cout << "\nAntrian Mahasiswa:" << endl;
    queue.display();

    cout << "\nDequeue Mahasiswa dari Antrian:" << endl;
    while (true) {
        queue.dequeue();
        char lanjut;
        cout << "Lanjutkan dequeue? (y/n): ";
        cin >> lanjut;
        if (lanjut != 'y' && lanjut != 'Y') break;
    }

    return 0;
}
