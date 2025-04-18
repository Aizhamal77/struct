#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

class bMoney {
private:
    long double amount; 

public:
    bMoney(long double amt = 0.0) : amount(amt) {}

    void input() {
        cout << "������� ����� (� �������: 100.25): ";
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
            cout << "������: ������� �� ����!\n";
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
            cout << "������: ������� �� ����!\n";
            return bMoney(0.0); 
        }
    }

    bMoney round() {
        long double intPart;
        long double fracPart = modfl(amount, &intPart); 
        if (fracPart >= 0.50) {
            intPart += 1;  
        }
        return bMoney(intPart);
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
        cout << "������� ����� ��� �������� � ��������: ";
        cin >> num;
    }

    void Operations() {
        cout << "\n���������� �������� � ��������:\n";

        // ��������
        bMoney result = money1 + money2;
        cout << "��������: ";
        result.output();
        cout << endl;

        // ���������
        result = money1 - money2;
        cout << "���������: ";
        result.output();
        cout << endl;

        // ���������
        result = money1 * money2;
        cout << "���������: ";
        result.output();
        cout << endl;

        // �������
        result = money1 / money2;
        cout << "�������: ";
        result.output();
        cout << endl;

        // ��������� ����� �� ������
        result = num * money1;
        cout << "����� * ������: ";
        result.output();
        cout << endl;

        // ������� ����� �� ������
        result = num / money2;
        cout << "����� / ������: ";
        result.output();
        cout << endl;
    }

    // ����� ��� �������� ����������
    void testRounding() {
        cout << "\n������������ ����������:\n";

        bMoney roundedMoney = money1.round();
        cout << "����������� �������� (1): ";
        roundedMoney.output();
        cout << endl;

        roundedMoney = money2.round();
        cout << "����������� �������� (2): ";
        roundedMoney.output();
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    MoneyOperations operations;
    operations.inputData();
    operations.Operations();
    operations.testRounding();

    return 0;
}
