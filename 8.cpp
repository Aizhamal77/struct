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

    cout << "������� �������� ��� x: ";
    cin >> x;
    cout << "������� �������� ��� y: ";
    cin >> y;

    cout << "�� ������: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "����� ������: x = " << x << ", y = " << y << endl;

    return 0;
}
