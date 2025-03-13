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

    cout << "Ââåäèòå çíà÷åíèå äëÿ x: ";
    cin >> x;
    cout << "Ââåäèòå çíà÷åíèå äëÿ y: ";
    cin >> y;

    cout << "Äî îáìåíà: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "Ïîñëå îáìåíà: x = " << x << ", y = " << y << endl;

    return 0;
}
