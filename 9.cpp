#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Rus");

    int* ap[10];  

    for (int i = 0; i < 10; ++i) {
        ap[i] = new int[10];  

      
        for (int j = 0; j < 10; ++j) {
            ap[i][j] = i * 10 + j;  
        }
    }

    cout << "Заполненные данные:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Массив " << i << ": ";
        for (int j = 0; j < 10; ++j) {
            cout << ap[i][j] << " "; 
        }
        cout << endl;
    }

    for (int i = 0; i < 10; ++i) {
        delete[] ap[i];  
    }

    return 0;
}
