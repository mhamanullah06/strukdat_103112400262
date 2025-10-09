#include <iostream> 

using namespace std;    

int main(){
    float hargaProduk =50000;
    float *ptrHarga;
    ptrHarga = &hargaProduk;


    cout << "Harga produk: "<<hargaProduk<<endl;
    cout << "alamat memori harga"<<ptrHarga<<endl;

    cout << "\n....Memberikan diskon 20% melalui pointer...."<<endl;
    *ptrHarga = *ptrHarga * 0.8;
    cout << "Harga produk setelah diskon: "<<hargaProduk<<endl;
    return 0;
}