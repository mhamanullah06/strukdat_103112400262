#include<iostream>

using namespace std;
int main(){
    float celcius, fahrenheit;
    cout << "Seberapa dingin lu:";
    cin >> celcius;
    fahrenheit = (9.0/5.0) * celcius + 32;
    cout << "Dingin lu itu setara sama suhu: " << fahrenheit << "derajat fahrenheit" <<endl;
    cout << "Itu dingin banget bjrr";
    return 0;   
}