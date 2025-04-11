#include <iostream>
using namespace std;

const int NUM_ARR = 10;   // Êîë-âî ìàññèâîâ
const int ARR_SIZE = 10;   // Ðàçìåð êàæäîãî ìàññèâà
const int TOT_SIZE = NUM_ARR * ARR_SIZE;  // Îáùèé ðàçìåð

class BigArr {
private:
    int* arr[NUM_ARR];

public:
    BigArr() {
        for (int i = 0; i < NUM_ARR; ++i)
            *(arr + i) = new int[ARR_SIZE];
    }

    ~BigArr() {
        for (int i = 0; i < NUM_ARR; ++i)
            delete[] * (arr + i);
    }

    // Ïåðåãðóçêà îïåðàòîðà []
    int& operator[](int index) {
        if (index < 0 || index >= TOT_SIZE) {
            cout << "Îøèáêà: âûõîä çà ãðàíèöû ìàññèâà!" << endl;
            exit(1);
        }

        int outer = index / ARR_SIZE;
        int inner = index % ARR_SIZE;

        return *(*(arr + outer) + inner);
    }

    // Ìåòîä çàïîëíåíèÿ ìàññèâà
    void fill() {
        for (int i = 0; i < TOT_SIZE; ++i)
            (*this)[i] = i;
    }

    // Ìåòîä âûâîäà ìàññèâà
    void show() {
        for (int i = 0; i < TOT_SIZE; ++i) {
            cout << (*this)[i] << " ";
            if ((i + 1) % ARR_SIZE == 0)
                cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    BigArr arr;
    arr.fill();
    cout << "Ñîäåðæèìîå ìàññèâà:" << endl;
    arr.show();

    return 0;
}
