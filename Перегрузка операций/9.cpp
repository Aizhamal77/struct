#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    static const int SIZE = 100;
    int arr[SIZE];
    int lower;
    int upper;

public:
    SafeArray(int lowerIndex, int upperIndex) {
        if (upperIndex - lowerIndex + 1 > SIZE) {
            throw out_of_range("Ðàçìåð ìàññèâà ïðåâûøàåò äîïóñòèìûé ïðåäåë.");
        }
        lower = lowerIndex;
        upper = upperIndex;
        for (int i = 0; i < SIZE; i++) {
            arr[i] = 0;
        }
    }

    int& operator[](int index) {
        if (index < lower || index > upper) {
            throw out_of_range("Èíäåêñ âûõîäèò çà ïðåäåëû ìàññèâà.");
        }
        return arr[index - lower];
    }

    void display() const {
        for (int i = lower; i <= upper; i++) {
            cout << "arr[" << i << "] = " << arr[i - lower] << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    try {
        SafeArray arr(100, 200);
        arr[100] = 10;
        arr[150] = 20;
        arr[200] = 30;

        arr.display();

        cout << "arr[150] = " << arr[150] << endl;

    }
    catch (const out_of_range& e) {
        cout << "Îøèáêà: " << e.what() << endl;
    }

    return 0;
}
