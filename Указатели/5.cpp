#include <iostream>
using namespace std;

class Arr {
private:
    float* arr;  
    int size;    

public:
    Arr(int s) : size(s) {
        arr = new float[size];  
    }

    ~Arr() {
        delete[] arr;  
    }

    void input() {
        cout << "Ââåäèòå " << size << " ýëåìåíòîâ ìàññèâà:\n";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    void output() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void add(const Arr& other, Arr& result) const {
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i]; 
        }
    }

    float& operator[](int index) {
        return arr[index];
    }

    const float& operator[](int index) const {
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    // Ìåòîä äëÿ âûïîëíåíèÿ âñåõ äåéñòâèé: ââîäà, ñëîæåíèÿ è âûâîäà
    void process(Arr& other, Arr& result) {
        input();
        other.input();
        add(other, result);
        output();
        result.output();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    const int SIZE = 5;  

    Arr arr1(SIZE);
    Arr arr2(SIZE);
    Arr result(SIZE);

    arr1.process(arr2, result);

    return 0;
}
