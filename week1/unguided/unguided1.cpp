#include <iostream>

using namespace std;

int main() {
    float angka1, angka2; // Deklarasi variabel bilangan pertama & kedua
    cout << "Masukkan bilangan pertama: ";
    cin >> angka1;
    cout << "Masukkan bilangan kedua: ";
    cin >> angka2;

    cout << "Penjumlahan: " << angka1 + angka2 << endl; //operasi penjumlahan
    cout << "Pengurangan: " << angka1 - angka2 << endl; //operasi pengurangan
    cout << "Perkalian: " << angka1 * angka2 << endl; //operasi perkalian
    if (angka2 != 0)    // Cek pembagian dengan nol
        cout << "Pembagian: " << angka1 / angka2 << endl;   //operasi pembagian
    else
        cout << "Pembagian: Tidak bisa dibagi 0!" << endl;  // Pesan error pembagian dengan nol

    return 0;
}
