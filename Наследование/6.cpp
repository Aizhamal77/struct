#include <iostream>
#include <stdexcept>
using namespace std;

class safearray {
protected:
    int* arr;
    int size;

public:
    safearray(int sz) : size(sz) {
        arr = new int[size];
    }

    virtual ~safearray() {
        delete[] arr;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Èíäåêñ çà ïðåäåëàìè äèàïàçîíà");
        }
        return arr[index];
    }
};

class safehilo : public safearray {
private:
    int lowerBound;
    int upperBound;

public:
    safehilo(int lower, int upper) : safearray(upper - lower + 1), lowerBound(lower), upperBound(upper) {}

    int& operator[](int index) {
        if (index < lowerBound || index > upperBound) {
            throw out_of_range("Èíäåêñ çà ïðåäåëàìè äèàïàçîíà");
        }
        return arr[index - lowerBound];
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    int lower, upper;
    cout << "Ââåäèòå íèæíþþ è âåðõíþþ ãðàíèöó ìàññèâà: ";
    cin >> lower >> upper;

    safehilo arr(lower, upper);

    for (int i = lower; i <= upper; ++i) {
        cout << "Ââåäèòå çíà÷åíèå äëÿ èíäåêñà " << i << ": ";
        cin >> arr[i];
    }

    for (int i = lower; i <= upper; ++i) {
        cout << "Çíà÷åíèå â èíäåêñå " << i << ": " << arr[i] << endl;
    }

    return 0;
}
