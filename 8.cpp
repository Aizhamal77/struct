#include <iostream>
using namespace std;

class safearay {
private:
    static const int LIMIT = 10; 
    int arr[LIMIT]; 

public:
    safearay() {
        for (int i = 0; i < LIMIT; ++i) {
            arr[i] = 0;
        }
    }

    void putel(int index, int value) {
        if (index >= 0 && index < LIMIT) {
            arr[index] = value;
        }
        else {
            cout << "Ошибка: индекс выходит за пределы массива!" << endl;
        }
    }

    int getel(int index) {
        if (index >= 0 && index < LIMIT) {
            return arr[index];
        }
        else {
            cout << "Ошибка: индекс выходит за пределы массива!" << endl;
            return -1; 
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    safearay sa1;
    int temp = 12345;

    sa1.putel(7, temp);
    temp = sa1.getel(7);
    cout << "Значение по индексу 7: " << temp << endl;

    sa1.putel(11, 98765);

    temp = sa1.getel(11);
    cout << "Значение по индексу 11: " << temp << endl;

    return 0;
}
