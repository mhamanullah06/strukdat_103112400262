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

void insertAfter(List &L, address P, address R) {
    if (R != Nil) {
        P->next = R->next; P->prev = R;
        if (R->next != Nil) R->next->prev = P;
        else L.last = P;
        R->next = P;
    }
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

void printReverse(List L) {
    address P = L.last;
    while (P != Nil) { cout << P->info << " "; P = P->prev; }
    cout << endl;
}

void smartInsert(List &L, infotype x) {
    address P = alokasi(x);
    if (L.first == Nil) {
        cout << "Smart Insert: List kosong, insert " << x << " di first" << endl;
        insertFirst(L, P);
    } else if (x < L.first->info) {
        cout << "Smart Insert: " << x << " < first, insert di first" << endl;
        insertFirst(L, P);
    } else if (x % 2 == 0) {
        cout << "Smart Insert: " << x << " genap, insert di last" << endl;
        insertLast(L, P);
    } else if (x == 7) {
        address Q = L.first;
        while (Q != Nil && Q->info != 5) Q = Q->next;
        if (Q != Nil) {
            cout << "Smart Insert: " << x << " di antara 5 dan 7" << endl;
            insertAfter(L, P, Q);
        } else {
            cout << "Smart Insert: kondisi khusus tidak ditemukan, insert di last" << endl;
            insertLast(L, P);
        }
    } else {
        cout << "Smart Insert: kondisi lain, insert di last" << endl;
        insertLast(L, P);
    }
}

void conditionalDelete(List &L) {
    cout << "Sebelum Conditional Delete: "; pritinfo(L);
    int count = 0; address P = L.first;
    while (P != Nil) {
        address nextP = P->next;
        if (P->info % 2 != 0) {
            if (P == L.first) { address del; deleteFirst(L, del); dealokasi(del); }
            else if (P == L.last) { address del; deleteLast(L, del); dealokasi(del); }
            else { address del; deleteAfter(L, del, P->prev); dealokasi(del); }
            count++;
        }
        P = nextP;
    }
    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: "; pritinfo(L);
}

void deleteByValue(List &L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) P = P->next;
    if (P == Nil) cout << "Nilai " << x << " tidak ditemukan" << endl;
    else {
        if (P == L.first) { address del; deleteFirst(L, del); dealokasi(del); }
        else if (P == L.last) { address del; deleteLast(L, del); dealokasi(del); }
        else { address del; deleteAfter(L, del, P->prev); dealokasi(del); }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
    }
}

void deleteAll(List &L) {
    int count = 0; address P;
    while (L.first != Nil) { deleteFirst(L, P); dealokasi(P); count++; }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

int main() {
    List L; L.first = Nil; L.last = Nil;
    cout << "ADVANCED OPERATIONS" << endl;
    cout << "SMART INSERT DEMO" << endl;

    smartInsert(L, 5);
    smartInsert(L, 3);
    smartInsert(L, 8);
    smartInsert(L, 6);
    smartInsert(L, 4);
    smartInsert(L, 7);

    cout << endl << "Hasil Smart Insert:" << endl;
    cout << "Forward: "; pritinfo(L);
    cout << "Backward: "; printReverse(L);

    cout << endl << "CONDITIONAL DELETE" << endl;
    conditionalDelete(L);

    cout << endl << "DELETE BY VALUE DEMO" << endl;
    deleteByValue(L, 6);
    deleteByValue(L, 10);
    cout << "List akhir: "; pritinfo(L);

    cout << endl << "DELETE ALL DEMO" << endl;
    deleteAll(L);

    return 0;
}