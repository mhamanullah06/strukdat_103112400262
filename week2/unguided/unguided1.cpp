#include <iostream>

using namespace std;

void tampilkanArray(int stok[], int jumlah) {
    cout << "[ ";
    for (int i = 0; i < jumlah; i++) {
        cout << stok[i];
        if (i < jumlah - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int hitungTotal(int stok[], int jumlah) {
    int total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += stok[i];
    }
    return total;
}

int* cariStokMinimum(int stok[], int jumlah) {
    int* terkecil = &stok[0];
    for (int i = 1; i < jumlah; i++) {
        if (stok[i] < *terkecil) {
            terkecil = &stok[i];
        }
    }
    return terkecil;
}

void tambahBonus(int* ptr) {
    *ptr += 10;
}

int main() {
    int stokBuku[] = {12, 8, 25, 5, 18};
    int jumlahBuku = 5;

    cout << "Stok Buku Awal:" << endl;
    tampilkanArray(stokBuku, jumlahBuku);

    int totalAwal = hitungTotal(stokBuku, jumlahBuku);
    cout << "Total semua stok buku: " << totalAwal << endl;

    int* stokTerkecil = cariStokMinimum(stokBuku, jumlahBuku);
    tambahBonus(stokTerkecil);

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;
    tampilkanArray(stokBuku, jumlahBuku);

    return 0;
}