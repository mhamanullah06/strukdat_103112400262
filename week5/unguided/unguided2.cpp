#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x; P->next = Nil; P->prev = Nil;
    return P;
}

void dealokasi(address &P) { delete P; P = Nil; }

void insertFirst(List &L, address P) {
    P->next = L.first; P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last; P->next = Nil;
    if (L.last != Nil) L.last->next = P;
    else L.first = P;
    L.last = P;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != Nil) {
        L.first = P->next;
        if (L.first != Nil) L.first->prev = Nil;
        else L.last = Nil;
        P->next = Nil; P->prev = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != Nil) {
        L.last = P->prev;
        if (L.last != Nil) L.last->next = Nil;
        else L.first = Nil;
        P->next = Nil; P->prev = Nil;
    }
}

void deleteAfter(List &L, address &P, address R) {
    if (R != Nil && R->next != Nil) {
        P = R->next;
        R->next = P->next;
        if (P->next != Nil) P->next->prev = R;
        else L.last = R;
        P->next = Nil; P->prev = Nil;
    }
}

void pritinfo(List L) {
    address P = L.first;
    while (P != Nil) { cout << P->info << " "; P = P->next; }
    cout << endl;
}

void deleteByValue(List &L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) P = P->next;

    if (P == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
        cout << "List tetap: "; pritinfo(L);
    } else {
        if (P == L.first) {
            address del; deleteFirst(L, del); dealokasi(del);
        } else if (P == L.last) {
            address del; deleteLast(L, del); dealokasi(del);
        } else {
            address del; deleteAfter(L, del, P->prev); dealokasi(del);
        }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
        cout << "Setelah deleteByValue(" << x << "): "; pritinfo(L);
    }
}

void deleteAll(List &L) {
    int count = 0; address P;
    while (L.first != Nil) { deleteFirst(L, P); dealokasi(P); count++; }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

int main() {
    List L; L.first = Nil; L.last = Nil;
    cout << "TASK 1: DELETE OPERATIONS" << endl;

    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));
    cout << "List awal: "; pritinfo(L);

    deleteByValue(L, 2);

    deleteByValue(L, 5);

    L.first = Nil; L.last = Nil;

    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));
    cout << "List setelah tambah data: "; pritinfo(L);

    deleteAll(L);

    return 0;
}
