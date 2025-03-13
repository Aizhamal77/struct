#include <iostream>
#include <iomanip>
using namespace std;

class bMoney {
private:
    long double amount;

public:
    explicit bMoney(long double money = 0.0) : amount(money) {}
    long double getAmount() const { return amount; }

    bMoney operator + (const bMoney& other) const {
        return bMoney(amount + other.amount);
    }

    bMoney operator - (const bMoney& other) const {
        return bMoney(amount - other.amount);
    }

    bMoney operator * (long double pricePerUnit) const {
        return bMoney(amount * pricePerUnit);
    }

    long double operator / (const bMoney& other) const {
        if (other.amount == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return amount / other.amount;
    }

    bMoney operator / (long double quantity) const {
        if (quantity == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return bMoney(amount / quantity);
    }

    void display() const {
        cout << "Сумма: " << fixed << setprecision(2) << amount << " единиц." << endl;
    }

    operator long double() const { return amount; }
};

int main() {
    setlocale(LC_ALL, "Rus");

    bMoney money1, money2, result;
    long double pricePerUnit, quantity;

    while (true) {
        cout << "Введите первую денежную сумму: ";
        long double amount1;
        cin >> amount1;
        money1 = bMoney(amount1);

        cout << "Введите вторую денежную сумму: ";
        long double amount2;
        cin >> amount2;
        money2 = bMoney(amount2);

        cout << "Введите цену за единицу (для умножения): ";
        cin >> pricePerUnit;

        cout << "Введите количество (для деления): ";
        cin >> quantity;

        result = money1 + money2;
        cout << "\nРезультат сложения: ";
        result.display();

        result = money1 - money2;
        cout << "\nРезультат вычитания: ";
        result.display();

        result = money1 * pricePerUnit;
        cout << "\nРезультат умножения на цену за единицу: ";
        result.display();

        long double divisionResult = money1 / money2;
        cout << "\nРезультат деления первой суммы на вторую: " << divisionResult << endl;

        result = money1 / quantity;
        cout << "\nРезультат деления первой суммы на количество: ";
        result.display();

        cout << "\nХотите продолжить (y/n)? ";
        char continueChoice;
        cin >> continueChoice;
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    return 0;
}
