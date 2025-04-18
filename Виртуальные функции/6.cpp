#include <iostream>
#include <iomanip>
using namespace std;

class bMoney {
private:
    long double amount; 

public:
    bMoney(long double amt = 0.0) : amount(amt) {}

    void input() {
        cout << "Ââåäèòå ñóììó (â ôîðìàòå: 100.25): ";
        cin >> amount;
    }

    void output() const {
        cout << fixed << setprecision(2) << "$" << amount;
    }

    bMoney operator+(const bMoney& other) const {
        return bMoney(amount + other.amount);
    }

    bMoney operator-(const bMoney& other) const {
        return bMoney(amount - other.amount);
    }

    bMoney operator*(const bMoney& other) const {
        return bMoney(amount * other.amount);
    }

    bMoney operator/(const bMoney& other) const {
        if (other.amount != 0) {
            return bMoney(amount / other.amount);
        }
        else {
            cout << "Îøèáêà: äåëåíèå íà íîëü!\n";
            return bMoney(0.0); 
        }
    }

    friend bMoney operator*(long double num, const bMoney& money) {
        return bMoney(num * money.amount);
    }

    friend bMoney operator/(long double num, const bMoney& money) {
        if (money.amount != 0) {
            return bMoney(num / money.amount);
        }
        else {
            cout << "Îøèáêà: äåëåíèå íà íîëü!\n";
            return bMoney(0.0); 
        }
    }

    long double getAmount() const {
        return amount;
    }
};

class MoneyOperations {
private:
    bMoney money1, money2;
    long double num;

public:
    void inputData() {
        money1.input();
        money2.input();
        cout << "Ââåäèòå ÷èñëî äëÿ îïåðàöèé ñ äåíüãàìè: ";
        cin >> num;
    }

    void Operations() {
        cout << "\nÐåçóëüòàòû îïåðàöèé ñ äåíüãàìè:\n";

        // Ñëîæåíèå
        bMoney result = money1 + money2;
        cout << "Ñëîæåíèå: ";
        result.output();
        cout << endl;

        // Âû÷èòàíèå
        result = money1 - money2;
        cout << "Âû÷èòàíèå: ";
        result.output();
        cout << endl;

        // Óìíîæåíèå
        result = money1 * money2;
        cout << "Óìíîæåíèå: ";
        result.output();
        cout << endl;

        // Äåëåíèå
        result = money1 / money2;
        cout << "Äåëåíèå: ";
        result.output();
        cout << endl;

        // Óìíîæåíèå ÷èñëà íà äåíüãè
        result = num * money1;
        cout << "×èñëî * äåíüãè: ";
        result.output();
        cout << endl;

        // Äåëåíèå ÷èñëà íà äåíüãè
        result = num / money2;
        cout << "×èñëî / äåíüãè: ";
        result.output();
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    MoneyOperations operations;
    operations.inputData();
    operations.Operations();

    return 0;
}
