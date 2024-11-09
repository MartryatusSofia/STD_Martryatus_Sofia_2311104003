#include <iostream>
#include <limits>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor untuk membersihkan semua elemen dari memori
    ~DoublyLinkedList()
    {
        deleteAll();
    }

    // Fungsi untuk menambahkan elemen di depan list (push)
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode; // Jika list kosong, tail juga mengarah ke node baru
        }
        head = newNode;
    }

    // Fungsi untuk menghapus elemen dari depan list (pop)
    void pop()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return; // Jika list kosong
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // Jika hanya satu elemen di list
        }
        delete temp; // Hapus elemen
    }

    // Fungsi untuk mengupdate data di list
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true; // Jika data ditemukan dan diupdate
            }
            current = current->next;
        }
        return false; // Jika data tidak ditemukan
    }

    // Fungsi untuk menghapus semua elemen di list
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menampilkan semua elemen di list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Fungsi untuk memvalidasi input integer
bool validateInput(int &input)
{
    if (cin.fail())
    {
        cin.clear();                                         // Menghapus error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus input yang tidak valid
        cout << "Invalid input. Please enter a valid number." << endl;
        return false;
    }
    return true;
}

int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!validateInput(choice))
            continue;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;

            if (validateInput(data))
            {
                list.push(data);
            }
            break;
        }
        case 2:
            list.pop();
            break;
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;

            if (!validateInput(oldData))
                continue;

            cout << "Enter new data: ";
            cin >> newData;

            if (!validateInput(newData))
                continue;

            bool updated = list.update(oldData, newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
            list.deleteAll();
            cout << "All data cleared." << endl;
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}