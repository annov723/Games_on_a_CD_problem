#include <iostream>
#include <string>

using namespace std;

int main( void ){

    int ile, dl, input; //ile nazw, jak dlugie, ile zostanie wprowadzonych nazw do sprawdzenia
    string snail; //ciag znakow
    

    cin >> ile >> dl;
    cin >> snail;
    cin >> input;

    char check[n*k]; //zawiera ciag znakow
    int check1[input][n*k]; //przypisuje możliwe dopasowania
    for( int i = 0; i < n*k; i++ ){ //uzupelniamy check1 literami, check2 na razie pusty
        check[i] = snail[i];
        check2[i] = 0; //puste
    }

    string titles[input]; //wprowadzone tytuly
    for( int i = 0; i < input; i++ ){
        cin >> titles[i];
    }

    for( int i = 0; i < input; i++) //przechodzimy przez kazda mozliwa kolejnosc tytulow
        for( int j = 0; j < input; j++ ){ //przechodzimy przez wszystkie tytuly dla danej kombinacji, np. od tytulu 1, od tytulu 2, itd.

        }

    

    return 0;
}