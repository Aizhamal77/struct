#include <iostream>
#include <cmath>
using namespace std;

double power(double n, int p = 2) {
    return pow(n, p);
}

double power(char n, int p = 2) {
    return pow(n, p);
}

double power(int n, int p = 2) {
    return pow(n, p);
}

double power(long n, int p = 2) {
    return pow(n, p);
}

double power(float n, int p = 2) {
    return pow(n, p);
}

int main() {
    setlocale(LC_ALL, "Rus");

    double d = 2.5;
    char c = 'A'; 
    int i = 3;
    long l = 4;
    float f = 2.2f;

    cout << "Power(double): " << power(d) << endl;
    cout << "Power(char): " << power(c) << endl;
    cout << "Power(int): " << power(i) << endl;
    cout << "Power(long): " << power(l) << endl;
    cout << "Power(float): " << power(f) << endl;

    cout << "Power(double, 3): " << power(d, 3) << endl;
    cout << "Power(char, 3): " << power(c, 3) << endl;
    cout << "Power(int, 3): " << power(i, 3) << endl;
    cout << "Power(long, 3): " << power(l, 3) << endl;
    cout << "Power(float, 3): " << power(f, 3) << endl;

    return 0;
}
