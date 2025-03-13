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
            cout << "Îøèáêà: äåëåíèå íà íîëü!" << endl;
            exit(1);
        }
        return amount / other.amount;
    }

    bMoney operator / (long double quantity) const {
        if (quantity == 0) {
            cout << "Îøèáêà: äåëåíèå íà íîëü!" << endl;
            exit(1);
        }
        return bMoney(amount / quantity);
    }

    void display() const {
        cout << "Ñóììà: " << fixed << setprecision(2) << amount << " åäèíèö." << endl;
    }

    operator long double() const { return amount; }
};

int main() {
    setlocale(LC_ALL, "Rus");

    bMoney money1, money2, result;
    long double pricePerUnit, quantity;

    while (true) {
        cout << "Ââåäèòå ïåðâóþ äåíåæíóþ ñóììó: ";
        long double amount1;
        cin >> amount1;
        money1 = bMoney(amount1);

        cout << "Ââåäèòå âòîðóþ äåíåæíóþ ñóììó: ";
        long double amount2;
        cin >> amount2;
        money2 = bMoney(amount2);

        cout << "Ââåäèòå öåíó çà åäèíèöó (äëÿ óìíîæåíèÿ): ";
        cin >> pricePerUnit;

        cout << "Ââåäèòå êîëè÷åñòâî (äëÿ äåëåíèÿ): ";
        cin >> quantity;

        result = money1 + money2;
        cout << "\nÐåçóëüòàò ñëîæåíèÿ: ";
        result.display();

        result = money1 - money2;
        cout << "\nÐåçóëüòàò âû÷èòàíèÿ: ";
        result.display();

        result = money1 * pricePerUnit;
        cout << "\nÐåçóëüòàò óìíîæåíèÿ íà öåíó çà åäèíèöó: ";
        result.display();

        long double divisionResult = money1 / money2;
        cout << "\nÐåçóëüòàò äåëåíèÿ ïåðâîé ñóììû íà âòîðóþ: " << divisionResult << endl;

        result = money1 / quantity;
        cout << "\nÐåçóëüòàò äåëåíèÿ ïåðâîé ñóììû íà êîëè÷åñòâî: ";
        result.display();

        cout << "\nÕîòèòå ïðîäîëæèòü (y/n)? ";
        char continueChoice;
        cin >> continueChoice;
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    return 0;
}
