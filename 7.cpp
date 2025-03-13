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
    cout << "������� �������� ������ � ������� $1,234,567,890,123.99: ";
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        long double amount = Money::mstold(input);
        cout << "���������� � �������� �������: " << amount << endl;
        cout << "\n������� �������� ������ � ������� $1,234,567,890,123.99: ";
    }

    return 0;
}
