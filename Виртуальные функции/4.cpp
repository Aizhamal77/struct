#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;
    int size;

public:
    Array() : ptr(nullptr), size(0) {}

    Array(int s) : size(s) {
        ptr = new int[s];
    }

    Array(const Array& a) {
        size = a.size;
        ptr = new int[size];
        for (int j = 0; j < size; j++)
            ptr[j] = a.ptr[j];
    }

    ~Array() {
        delete[] ptr;
    }

    Array& operator=(const Array& a) {
        if (this == &a) return *this;

        delete[] ptr;
        size = a.size;
        ptr = new int[size];
        for (int j = 0; j < size; j++)
            ptr[j] = a.ptr[j];
        return *this;
    }

    int& operator[](int j) {
        return ptr[j];
    }

    const int& operator[](int j) const {
        return ptr[j];
    }

    int getSize() const {
        return size;
    }
};

class ArrayManager {
private:
    const int ASIZE = 10;
    Array arr1, arr2, arr3, arr4;

public:
    void run() {
        fillArray();
        copyAndAssign();
        displayArrays();
    }

private:
    void fillArray() {
        arr1 = Array(ASIZE);
        for (int j = 0; j < ASIZE; j++)
            arr1[j] = j * j;
    }

    void copyAndAssign() {
        arr2 = Array(arr1);
        arr4 = arr3 = arr1;
    }

    void displayArray(const string& name, const Array& arr) const {
        cout << name << ": ";
        for (int j = 0; j < arr.getSize(); j++)
            cout << arr[j] << " ";
        cout << endl;
    }

    void displayArrays() const {
        displayArray("arr1", arr1);
        displayArray("arr2", arr2);
        displayArray("arr3", arr3);
        displayArray("arr4", arr4);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    ArrayManager manager;
    manager.run();
    return 0;
}
