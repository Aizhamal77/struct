#include <iostream>
using namespace std;

class Frac {
private:
    int num; 
    int den; 

    void reduce() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    Frac() : num(0), den(1) {}

    Frac(int n, int d) : num(n), den(d) {
        if (den == 0) {
            cerr << "Ошибка: знаменатель не может быть 0.\n";
            exit(1);
        }
        reduce();
    }

    Frac operator+(const Frac& f) const {
        return Frac(num * f.den + f.num * den, den * f.den);
    }

    Frac operator-(const Frac& f) const {
        return Frac(num * f.den - f.num * den, den * f.den);
    }

    Frac operator*(const Frac& f) const {
        return Frac(num * f.num, den * f.den);
    }

    Frac operator/(const Frac& f) const {
        if (f.num == 0) {
            cerr << "Ошибка: деление на ноль.\n";
            exit(1);
        }
        return Frac(num * f.den, den * f.num);
    }

    friend istream& operator>>(istream& in, Frac& f) {
        char slash;
        in >> f.num >> slash >> f.den;
        if (f.den == 0) {
            cerr << "Ошибка: знаменатель не может быть 0.\n";
            exit(1);
        }
        f.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Frac& f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Frac f1, f2, result;
    char op;
    char cont = '1';

    cout << "=== Калькулятор дробей ===\n";

    while (cont == '1') {
        cout << "\nВведите выражение (пример: 1/2 + 3/4): ";
        cin >> f1 >> op >> f2;

        switch (op) {
        case '+': result = f1 + f2; break;
        case '-': result = f1 - f2; break;
        case '*': result = f1 * f2; break;
        case '/': result = f1 / f2; break;
        default:
            cout << "Неизвестная операция!\n";
            continue;
        }

        cout << "Результат: " << result << "\n";
        cout << "Введите 1 для нового выражения или 0 для выхода: ";
        cin >> cont;
    }

    cout << "До свидания!\n";
    return 0;
}
