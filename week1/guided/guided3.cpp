#include<iostream>    

using namespace std;       

int main() {
    int r = 20;             // Inisialisasi variabel r dengan nilai 20
    int s;                  // Deklarasi variabel s (belum ada nilai)

    s = 20 + ++r;           // Pre-increment: r = 21 dulu, lalu s = 20 + 21 = 41
    cout << "Nilai r saat ini: " << r << endl;  // Menampilkan r = 21
    cout << "Nilai s saat ini: " << s << endl;  // Menampilkan s = 41

    return 0;               
}
