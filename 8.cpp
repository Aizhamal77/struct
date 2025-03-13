#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "Rus");

    int x, y;

    cout << "Введите значение для x: ";
    cin >> x;
    cout << "Введите значение для y: ";
    cin >> y;

    cout << "До обмена: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "После обмена: x = " << x << ", y = " << y << endl;

    return 0;
}
