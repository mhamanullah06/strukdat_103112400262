#include <iostream>

using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};  // Indeks 0-9    
string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};   // Indeks 10-19 
string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};  // Indeks (20,30,...,90)

string terbilang(int a) {     // Fungsi untuk mengubah angka menjadi kata
    if (a < 10) return satuan[a];   // Jika a < 10, langsung ambil dari array satuan               
    else 
    if (a < 20) return belasan[a - 10]; // Jika a < 20, ambil dari array belasan dengan indeks (a-10)
    else 
    if (a < 100) {  // Jika a < 100, pecah menjadi puluhan dan satuan      
        int p = a / 10; // Puluhan
        int s = a % 10; // Satuan
        if (s == 0) return puluhan[p]; // Jika satuan 0, hanya puluhan
        else return puluhan[p] + " " + satuan[s]; // Gabungkan puluhan dan satuan
    } else      
    if (a == 100) return "seratus"; // Jika a = 100
    else
    return "di luar jangkauan"; // Jika a > 100
}

int main() {
    int a; // Deklarasi variabel a
    cout << "Masukkan angka (0-100): "; 
    cin >> a;   // Input angka
    cout << a << " : " << terbilang(a) << endl; // Tampilkan hasil konversi
    return 0;
}
