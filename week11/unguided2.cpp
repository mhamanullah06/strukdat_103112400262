#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED
#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef mahasiswa infotype;
typedef struct elmlist *address;

struct elemen{
    infotype info;
    address next;
}

struct list{
    address first;
};

void createList(list &L);
address alokasi(infotype x);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address Prec, address P);
address findElm(list L, string nim);
void printInfo(list L);

#endif // CIRCULAR_H_INCLUDED