#include<iostream>
#include<stack>
#include<string>

using namespace std;
bool isPalindrome(string str){
    stack<char>s;

    for(char ch : str){
        s.push(ch);
    }
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != s.top()) {
            return false; // Not a palindrome
        }
        s.pop();
    }
    return true;
}
int main(){
    string str;
    cout << "Masukkan kalimat: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}