#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    insertLastAnak(P1->anak, alokasiAnak(10));
    insertLastAnak(P1->anak, alokasiAnak(11));

    insertLastAnak(P2->anak, alokasiAnak(20));
    insertFirstAnak(P2->anak, alokasiAnak(19));

    printInfo(L);

    cout << "Menghapus anak terakhir dari induk1..." << endl;
    address_anak PDel;
    deleteLastAnak(P1->anak, PDel);

    printInfo(L);
    
    return 0;
}