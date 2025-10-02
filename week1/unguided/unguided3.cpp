#include <iostream>
using namespace std;
int main () {
    int a;
    cout << "Masukkan tinggi segitiga: ";
    cin >> a;
    for (int i = 0; i <= a; i++) { // untuk mengatur baris
        for (int j = 0; j <= a*2; j++){ // untuk mengatur kolom
            if (a - j == 0) { // tengah segitiga
                cout << "* "; // tanda bintang
                for (int k = 0; k < j; k++) {  // untuk segitiga sebelah kanan tanda bintang
                    if (k+1 <= a-i) {   // untuk membatasi pencetakan angka setiap barisnya
                        cout << k + 1 << " ";
                    }
                }
            } else if (j <= a) { // untuk segitiga sebelah kiri tanda bintang
                if (j+1 <= i) {  // untuk membatasi pencetakan angka setiap barisnya
                    cout << "  ";
                } else { // untuk mencetak angka
                    cout << a-j << " ";
                }
            }
        }
        cout << endl;
    }
    
}