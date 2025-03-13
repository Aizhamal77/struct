#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

class Money {
public:
    static long double mstold(const string& moneyStr) {
        string cleanedStr;
        for (char c : moneyStr) {
            if (isdigit(c) || c == '.') {
                cleanedStr += c;
            }
        }

        return stold(cleanedStr);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    string input;
    cout << "Ââåäèòå äåíåæíóþ ñòðîêó â ôîðìàòå $1,234,567,890,123.99: ";
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        long double amount = Money::mstold(input);
        cout << "Ýêâèâàëåíò â ÷èñëîâîì ôîðìàòå: " << amount << endl;
        cout << "\nÂâåäèòå äåíåæíóþ ñòðîêó â ôîðìàòå $1,234,567,890,123.99: ";
    }

    return 0;
}
