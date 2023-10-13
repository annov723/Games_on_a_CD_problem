#include <iostream>
#include <string>

using namespace std;

int main( void ){

    int ile, dl, input; //ile nazw, jak dlugie, ile zostanie wprowadzonych nazw do sprawdzenia
    string snail; //ciag znakow
    

    cin >> ile >> dl;
    cin >> snail;
    cin >> input;

    char check[ile * dl]; //zawiera ciag znakow
    int check1[input][ile * dl]; //przypisuje możliwe dopasowania
    int picker[input]; //na koniec zeby sprawdzic czy mamy dopasowanie
    for( int i = 0; i < ile * dl; i++ ) check[i] = snail[i]; //uzupelniamy check1 literami, check2 na razie pusty
    
    for( int i = 0; i < input; i++ ){
        picker[i] = 1; //na poczatku zakladamy ze jest dobrze
        for( int j = 0; j < ile * dl; j++ ) check1[i][j] = 0;
    }

    string titles[input]; //wprowadzone tytuly
    for( int i = 0; i < input; i++ ){
        cin >> titles[i];
    }

    for( int i = 0; i < input; i++){ //przechodzimy przez kazda mozliwa kolejnosc tytulow 0 - 10, 1 - 0, 2 - 1, itd.
        for( int j = 0; j < input; j++ ){ //przechodzimy przez wszystkie tytuly dla danej kombinacji, np. od tytulu 1, od tytulu 2, itd.
            for( int k = 0; k < ile * dl; k++ ){ //przechodzimy po calym ciagu

                if( titles[( i + j ) % input][0] == check[k] ){ //i - od ktorej pozycji zaczynamy, j - ktory z kolei tytul probujemy dopasowac
                    if( check1[i][k] == 0 ){ // i - sprawdzana kombinacja tytulow
                        int flag = 1; //mamy match
                        for( int l = 1; l < dl; l++ ){ //ilosc iter w jednym elemencie
                            if( titles[( i + j ) % input][l] != check[k+l] || check1[i][k+l] != 0 ){ //jak coś się nie zgadza to przerwie i flag = 0
                                flag = 0;
                                break;
                            }
                        }
                        if( flag == 1 ){ //jak match to dla odpowiedniej kombinacji uzupelniamy
                            for( int l = 0; l < dl; l++ ) check1[i][k+l] = ( i + j ) % input;
                            break;
                        }
                    } 
                }
            }
        }
    }
    
    for( int i = 0; i < input; i++ ){
         for( int j = 0; j < ile * dl; i++ ){ //jeśli na koniec cała tablica nie została uzupełniona to bajo
            if( check1[i][j] == 0 ){
                picker[input] = 0; //jak nie spelnil warunkow to "usuwamy"
                break;
            }
        }
    }

    for( int i = 0; i < input; i++ ){//sprawdzamy dla kazdej mozliwej kombinacji tytulow
        if( picker[i] == 1 ){
            cout << "YES" << i << endl;
            int keeper = 0;
            for( int j = 0; j < ile * dl; j++ ){
                if( check1[i][j] != keeper ){
                    cout << check1[i][j] << " ";
                    keeper = check1[i][j];
                }
            }
            
        }
    }

    cout << "NO" << endl;

    return 0;
}