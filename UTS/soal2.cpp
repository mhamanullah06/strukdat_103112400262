#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};

// deklarasi head dan tail
Node* head = nullptr;
Node* tail = nullptr;

// insert nilai di akhir list
void insertAkhir(int value){
    // membuat node baru
    Node* baru = new Node {value, nullptr, nullptr};

    // jika list kosong maka head dan tail menunjuk ke node baru
    if (head == nullptr){
        head = tail = baru;
    }else{ // jika tidak maka tail next menunjuk ke node baru dan prev node baru menunjuk ke tail
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Masukan nilai: " << value << endl;
};

// delete nilai di akhir list
void deleteAkhir(){
    // jika list kosong maka tidak ada yang dihapus
    if (tail == nullptr) return;
    Node* hapus = tail;
    cout << hapus->data << " Terhapus" << endl;

    // jika list hanya memiliki satu node maka head dan tail di set ke nullptr
    if (head == tail){
        head = tail = nullptr;
    }else{ // jika tidak maka tail di geser ke prev dan next di set ke nullptr
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete hapus;
};

// view list dari depan ke belakang
void view(){
    Node* temp = head;
    cout << "List ";

    // ketika temp tidak nullptr maka tampilkan data dan lanjut ke next
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

// reverse list tanpa membuat node baru
void reverseList(){
    Node* current = head;
    Node* temp = nullptr;

    // ketika current tidak nullptr maka tukar next dan prev
    while (current != nullptr){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // jika temp tidak nullptr maka head di set ke prev dari temp
    if (temp != nullptr){
        head = temp->prev;
    }
};

int main() {
    // variabel pilihan dan nilai
    int pilihan, nilai;

    // menu pilihan
    do{
        cout << "menu: 1 insert, 2 delete (last), 3 view (depan)" << "4 reverse & view (depan), 0 exit\n";
        cin >> pilihan;

        // proses pilihan
        switch (pilihan){
            // insert nilai di akhir list
            case 1:
            cout << "Masukan nilai: ";
            cin >> nilai;
            insertAkhir(nilai);
            break;

            // delete nilai di akhir list
            case 2:
            deleteAkhir();
            break;

            // view list dari depan ke belakang
            case 3:
            view();
            break;

            // reverse list tanpa membuat node baru
            case 4:
            cout << "Sebelum di reverse: " << endl;
            view();
            reverseList();
            cout << "Setelah di reverse: " << endl;
            view();
            break;

            // exit program
            case 0:
            break;

            default:
            cout << " Pilihan tidak valid\n";
        }
    }while (pilihan != 0);
    return 0;
};