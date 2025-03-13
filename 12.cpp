#include <iostream>
using namespace std;


struct fraction {
    int numerator;  
    int denominator; 
};

fraction fadd(const fraction& a, const fraction& b) {
    fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}


fraction fsub(const fraction& a, const fraction& b) {
    fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}


fraction fmul(const fraction& a, const fraction& b) {
    fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}


fraction fdiv(const fraction& a, const fraction& b) {
    fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}


void printFraction(const fraction& f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    fraction f1, f2;


    cout << "������� ������ ����� (��������� � �����������): ";
    cin >> f1.numerator >> f1.denominator;

    cout << "������� ������ ����� (��������� � �����������): ";
    cin >> f2.numerator >> f2.denominator;

    fraction sum = fadd(f1, f2);
    cout << "�����: ";
    printFraction(sum);

  
    fraction diff = fsub(f1, f2);
    cout << "��������: ";
    printFraction(diff);


    fraction product = fmul(f1, f2);
    cout << "������������: ";
    printFraction(product);

  
    if (f2.numerator != 0) {
        fraction quotient = fdiv(f1, f2);
        cout << "�������: ";
        printFraction(quotient);
    }
    else {
        cout << "������! ������� �� ����." << endl;
    }

    return 0;
}
