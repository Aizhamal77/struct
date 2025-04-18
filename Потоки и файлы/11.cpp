#include <iostream>
#include <iomanip>  
using namespace std;

class bMoney {
private:
    int dollars;  
    int cents;   

public:
    bMoney() : dollars(0), cents(0) {}

    bMoney(int d, int c) : dollars(d), cents(c) {
        if (cents >= 100) {
            dollars += cents / 100;
            cents %= 100;
        }
    }

    friend ostream& operator<<(ostream& out, const bMoney& money) {
        out << "$" << money.dollars << ".";
        out << setfill('0') << setw(2) << money.cents; 
        return out;
    }

    friend istream& operator>>(istream& in, bMoney& money) {
        char ch;
        in >> money.dollars >> ch >> money.cents; 
        if (!in || ch != '.') {  
            in.setstate(ios::failbit);  
        }
        return in;
    }

    void setMoney(int d, int c) {
        dollars = d;
        cents = c;
    }

    int getDollars() const {
        return dollars;
    }

    int getCents() const {
        return cents;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    bMoney myMoney; 

    cout << "Ââåäèòå ñóììó äåíåã (ôîðìàò: dollars.cents, íàïðèìåð, 5.99): ";
    cin >> myMoney;

    if (cin.fail()) {
        cout << "Îøèáêà ââîäà. Ïîæàëóéñòà, ââåäèòå êîððåêòíîå çíà÷åíèå." << endl;
    }
    else {
        cout << "Âû ââåëè: " << myMoney << endl;  
    }

    return 0;
}
