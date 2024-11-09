#include <iostream>
using namespace std;

const int maksimalQueue = 5;    //maksimal antrian
int front =0;                   //Penanda antrian
int back = 0;                   //Penanda
string queueTeller[5];          //fungsi pengecekan

bool isFull()
{ //Pengecekan antrian penuh atau tidak
    if(back == maksimalQueue)
    {
        return true; //=1
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{// Antriannya kosong atau tidak
    if(back==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(string data)
{ // Fungsi Menambahkan antrian
    if(isFull())
    {
        cout << "Antrian Penuh" << endl;
    }
    else
    {
        if(isEmpty())
        { //Kondisi ketika queue kosong
        queueTeller[0] = data;
        front++;
        back++;
        }
        else 
        {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if(isEmpty())
    {
        cout << "Antrian Penuh" << endl;
    }
    else
    {
        for (int i=0; i < back - 1; i++) //pindahkan elemen ke depan
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] =""; // kosongkan elemen terakhit
        back--;
    }
}

int countQueue()
{ //Fungsi menghitung banyak antrian
    return back;
}

void clearQueue()
{/// Fungsi menghapus semua antrian
    if(isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        for(int i =0; i < back; i++)
        {
            queueTeller[i]= "";
        }
        back = 0;
        front = 0;
    }    
}

void viewQueue()
{ // Fungsi melihat antrian 
    cout << "Data Antrian teller: " << endl;
    for (int i =0; i< maksimalQueue; i++)
    {
        if(queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue()<< endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    return 0;
}