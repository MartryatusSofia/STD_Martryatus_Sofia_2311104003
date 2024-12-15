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

void deleteNode(Node* head, int value){
    if(isListEmpty(head)) return;

    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    while (current !=nullptr && current->data !=value){
        previous = current;
        current = current->next;
    }

    if(current != nullptr){
        previous->next = current-> next;
        delete current;
    }
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

    cout << "Sebelum dihapus: ";
    printList(head);  

    deleteNode(head, 10); 

    cout << "Setelah dihapus: ";
    printList(head);

    return 0;
}
