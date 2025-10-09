#include <iostream>
using namespace std;    

int main() {
    int bukuPerHari[7]={2,1,3,2,4,5,1}; // Inisialisasi array dengan jumlah buku yang dibaca setiap hari selama seminggu
    int totalBuku=0; 

    cout<<"Laporan Membaca Buku Selama Seminggu"<<endl;
    for (int i=0; i<7; i++) {
        
        cout<<"Hari ke-"<<i+1<<": "<<bukuPerHari[i];
        <<"buku."<<endl;
        totalBuku += bukuPerHari[i];

    }
}
