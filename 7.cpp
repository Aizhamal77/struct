#include <iostream>
#include <cmath>
using namespace std;

class fraction {
private:
    int chis, zznam;

    int gcd(int a, int b) {  // Нахождение НОД
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void lowterms() {
        int divisor = gcd(abs(chis), abs(zznam));
        chis /= divisor;
        zznam /= divisor;
    }

public:
    fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Ошибка: деление на 0!" << endl;
            exit(1);
        }
        chis = num;
        zznam = denom;
        lowterms();  // Приводим к несократимому виду сразу при инициализации
    }

    void setFraction() {
        cout << "Введите числитель: ";
        cin >> chis;
        cout << "Введите знаменатель: ";
        cin >> zznam;
        if (zznam == 0) {
            cout << "Ошибка: деление на 0!" << endl;
            exit(1);
        }
        lowterms();
    }

    void display() const {
        cout << chis << "/" << zznam;
    }

    fraction operator + (const fraction& f) const {
        int num = chis * f.zznam + f.chis * zznam;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator - (const fraction& f) const {
        int num = chis * f.zznam - f.chis * zznam;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator * (const fraction& f) const {
        int num = chis * f.chis;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator / (const fraction& f) const {
        if (f.chis == 0) {
            cout << "Ошибка: деление на 0!" << endl;
            exit(1);
        }
        int num = chis * f.zznam;
        int denom = zznam * f.chis;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    bool operator == (const fraction& f) const {
        return chis == f.chis && zznam == f.zznam;
    }

    bool operator != (const fraction& f) const {
        return !(*this == f);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    fraction f1, f2, result;
    int choice;

    f1.setFraction();
    f2.setFraction();

    do {
        cout << "\nМеню калькулятора дробей:" << endl;
        cout << "1. Сложение" << endl;
        cout << "2. Вычитание" << endl;
        cout << "3. Умножение" << endl;
        cout << "4. Деление" << endl;
        cout << "5. Выход" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            result = f1 + f2;
            cout << "Результат сложения: ";
            result.display();
            cout << endl;
            break;
        case 2:
            result = f1 - f2;
            cout << "Результат вычитания: ";
            result.display();
            cout << endl;
            break;
        case 3:
            result = f1 * f2;
            cout << "Результат умножения: ";
            result.display();
            cout << endl;
            break;
        case 4:
            result = f1 / f2;
            cout << "Результат деления: ";
            result.display();
            cout << endl;
            break;
        case 5:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
        }

    } while (choice != 5);

    return 0;
}
