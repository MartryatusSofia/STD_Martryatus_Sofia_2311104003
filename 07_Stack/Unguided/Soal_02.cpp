#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string reverseWords(string str) {
    stack<string> s;
    stringstream ss(str);
    string word;

    // Pisahkan kata dan push ke stack
    while (ss >> word) {
        s.push(word);
    }

    // Pop kata dari stack dan gabungkan
    string reversedString = "";
    while (!s.empty()) {
        reversedString += s.top() + " ";
        s.pop();
    }

    // Hapus spasi ekstra di akhir
    reversedString.pop_back();

    return reversedString;
}

int main() {
    string str;
    cout << "Masukkan kalimat: ";
    getline(cin, str);

    string reversed = reverseWords(str);
    cout << "Kalimat yang dibalik: " << reversed << endl;

    return 0;
}