#include<iostream>

using namespace std;

int main() {
    double total_pembelian, diskon; // Deklarasi variabel total_pembelian dan diskon
    cout << "Berapa kamu belanja: Rp.";
    cin >> total_pembelian; // Input total pembelian
    if(total_pembelian >= 30000) {
        diskon = 0.1 * total_pembelian; // Hitung diskon 10%
        cout << "Kamu dapat diskon sebesar " << diskon << " orang kaya lu bocah";
    } else {
        cout << "Kamu belanjanya masih dikit, Tambahin lah,biar gua kaya";
    }
}