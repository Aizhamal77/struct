#include <iostream>
using namespace std;

class Matrix {
private:
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE][MAX_SIZE];
    int rows, cols;

public:
    Matrix(int r, int c) {
        rows = r <= MAX_SIZE ? r : MAX_SIZE;
        cols = c <= MAX_SIZE ? c : MAX_SIZE;
    }

    void putel(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            arr[row][col] = value;
        }
        else {
            cout << "Ошибка: индекс за пределами матрицы!" << endl;
        }
    }

    int getel(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return arr[row][col];
        }
        else {
            cout << "Ошибка: индекс за пределами матрицы!" << endl;
            return -1;  
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Matrix m1(3, 4);
    int temp = 12345;

    m1.putel(2, 3, temp);  
    temp = m1.getel(2, 3);  

    cout << "Значение в матрице: " << temp << endl;

    return 0;
}
