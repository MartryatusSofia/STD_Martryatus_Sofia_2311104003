#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* alokasi(int value) {
    Node* newNode = new Node; 
    if (newNode != nullptr) { 
        newNode->data = value; 
        newNode->next = nullptr; 
    }
    return newNode; 
}

bool isListEmpty(Node* head) {
    return head == nullptr; 
}

void insertFirst(Node*& head, int value) {
    Node* newNode = alokasi(value); 
    if (newNode !=nullptr ) {
        newNode->next = head;
        head = newNode; 
    }
} 

void insertLast(Node* &head, int value) {
    Node* newNode = alokasi(value); 
    if (newNode != nullptr) {
        if (isListEmpty(head)) {  
            head = newNode;       
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { 
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }
}

bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true; 
        }
        temp = temp->next;
    }
    return false; 
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;  

    insertFirst(head, 10);  
    insertLast(head, 20);    
    insertFirst(head, 5);   

    cout << "Isi List: ";
    printList(head);  

    if (searchNode(head, 20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }

    int panjang = countNodes(head);
    cout << "Panjang linked list: " << panjang << endl;

    return 0;
}
