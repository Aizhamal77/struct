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


    cout << "Введите первую дробь (числитель и знаменатель): ";
    cin >> f1.numerator >> f1.denominator;

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    cin >> f2.numerator >> f2.denominator;

    fraction sum = fadd(f1, f2);
    cout << "Сумма: ";
    printFraction(sum);

  
    fraction diff = fsub(f1, f2);
    cout << "Разность: ";
    printFraction(diff);


    fraction product = fmul(f1, f2);
    cout << "Произведение: ";
    printFraction(product);

  
    if (f2.numerator != 0) {
        fraction quotient = fdiv(f1, f2);
        cout << "Частное: ";
        printFraction(quotient);
    }
    else {
        cout << "Ошибка! Деление на ноль." << endl;
    }

    return 0;
}
