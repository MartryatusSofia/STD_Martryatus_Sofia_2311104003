/*contoh penggunaan if else'*/
#include <iostream>

using namespace std;
int main(){
    double tot_pembelian, diskon;
    cout<<"total pembelian: Rp = ";
    cin>>tot_pembelian;
    diskon = 0;
    if(tot_pembelian >= 100000)
        diskon = 0.05*tot_pembelian;
    else
        diskon = 0;
    cout<<"besar diskon = Rp" <<diskon;
}