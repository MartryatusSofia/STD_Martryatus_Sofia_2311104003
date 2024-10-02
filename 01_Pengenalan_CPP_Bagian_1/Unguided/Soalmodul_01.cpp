#include <iostream>
using namespace std;

int main(){
    float bilangan1, bilangan2;

    cout<<"Masukkan bilangan pertama:";
    cin>>bilangan1;
    cout<<"Masukkan bilangan kedua:";
    cin>>bilangan2;

    float penjumlahan = bilangan1 + bilangan2;
    cout <<"Hasil penjumlahan:"<<penjumlahan<<endl;
    float pengurangan = bilangan1 - bilangan2;
    cout <<"Hasil pengurangan:"<<pengurangan<<endl;
    float perkalian = bilangan1 * bilangan2;
    cout <<"Hasil perkalian:"<<perkalian<<endl;
    float pembagian = bilangan1/bilangan2;
    cout <<"Hasil pembagian:"<<pembagian<<endl;
}