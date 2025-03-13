#include <iostream>
using namespace std;

class Fraction {
private:
    int chis;   // Числитель
    int znam; // Знаменатель

public:
    Fraction() : chis(0), znam(1) {}

    Fraction(int num, int den) : chis(num), znam(den) {}

    void input() {
        cout << "Введите числитель: ";
        cin >> chis;
        cout << "Введите знаменатель: ";
        cin >> znam;
        while (znam == 0) {
            cout << "Знаменатель не может быть равен 0. Введите снова: ";
            cin >> znam;
        }
    }

    void display() const {
        cout << chis << "/" << znam;
    }

    static Fraction average(Fraction* fractions, int size) {
        int totalNum = 0;
        int totalDen = 0;

        for (int i = 0; i < size; i++) {
            totalNum += fractions[i].chis * fractions[i].znam;
            totalDen += fractions[i].znam * fractions[i].znam;
        }

        return Fraction(totalNum, totalDen);
    }

    Fraction add(const Fraction& other) const {
        int num = chis * other.znam + other.chis * znam;
        int den = znam * other.znam;
        return Fraction(num, den);
    }

    double toDecimal() const {
        return (double)chis / znam;
    }
};

void inputFractions(Fraction* fractions, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Дробь " << i + 1 << ":\n";
        fractions[i].input();
    }
}

void displayFractions(Fraction* fractions, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Дробь " << i + 1 << ": ";
        fractions[i].display();
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите количество дробей: ";
    cin >> n;

    Fraction* fractions = new Fraction[n];

    inputFractions(fractions, n);

    cout << "\nДроби, которые вы ввели:\n";
    displayFractions(fractions, n);

    Fraction avg = Fraction::average(fractions, n);

    cout << "\nСреднее значение дробей: ";
    avg.display();
    cout << endl;

    delete[] fractions;
    return 0;
}
