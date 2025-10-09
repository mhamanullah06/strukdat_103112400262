#include<iostream>

using namespace std;

int main(){
    float celcius, fahrenheit; // Deklarasi variabel celcius dan fahrenheit

    cout << "Seberapa dingin lu:";
    cin >> celcius;                 // Input suhu dalam celcius

    fahrenheit = (9.0/5.0) * celcius + 32;  // Konversi ke fahrenheit

    cout << "Dingin lu itu setara sama suhu: " << fahrenheit << "derajat fahrenheit" <<endl;
    cout << "Itu dingin banget bjrr";

    return 0;   
}