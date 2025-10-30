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

void insertBefore(List &L, address P, address R) {
    if (R != Nil) {
        cout << "Berhasil insert " << P->info << " sebelum " << R->info << endl;
        P->next = R; P->prev = R->prev;
        if (R->prev != Nil) R->prev->next = P;
        else L.first = P;
        R->prev = P;
    }
}

void pritinfo(List L) {
    cout << "Forward: ";
    address P = L.first;
    while (P != Nil) { cout << P->info << " "; P = P->next; }
    cout << endl;
}

void printReverse(List L) {
    cout << "Backward: ";
    address P = L.last;
    while (P != Nil) { cout << P->info << " "; P = P->prev; }
    cout << endl;
}

int main() {
    List L; L.first = Nil; L.last = Nil;

    cout << "TASK 1: INSERT OPERATIONS" << endl;

    insertLast(L, alokasi(1));
    insertLast(L, alokasi(3));
    insertLast(L, alokasi(2));

    cout << "List awal:" << endl;
    pritinfo(L);
    printReverse(L);


    address P1 = alokasi(4);
    insertBefore(L, P1, L.last); 

    address P2 = alokasi(5);
    insertBefore(L, P2, L.first); 

    cout << "List setelah insertBefore:" << endl;
    pritinfo(L);
    printReverse(L);

    return 0;
}
