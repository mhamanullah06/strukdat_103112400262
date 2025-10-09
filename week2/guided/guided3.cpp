#include <iostream>
#include <string>

using namespace std;    

float hitungRataRata(int nilaiTugas, int nilaiUTS){
    return (nilaiTugas + nilaiUTS) / 2.0f;   
}

void cetakProfil(string nama, float nilai){
    cout << "Nama: " << nama << endl;
    cout << "Nilai: " << nilai << endl;
}

void beriNilaiBonus(float &nilai){
    nilai += 5.0f; 
}

int main(){
    string namaSiswa="Budi";
    int Tugas=80, uts=90;

    float nilaiAkhir = hitungRataRata(Tugas, uts);

    cout << "Profil Siswa" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout << "\nMemberikan nilai bonus 5 poin" << endl;
    beriNilaiBonus(nilaiAkhir);

    cout << "Profil Siswa setelah bonus" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    return 0;
}