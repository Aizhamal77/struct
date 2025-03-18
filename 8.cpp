#include <iostream>
#include <string>
using namespace std;

class Pstring {
protected:
    string str; 

public:
    Pstring() : str("") {}
    Pstring(const string& s) : str(s) {}

    void setString(const string& s) {
        str = s;
    }

    string getString() const {
        return str;
    }

    void display() const {
        cout << str << endl;
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {}
    Pstring2(const string& s) : Pstring(s) {}

    Pstring2& left(const string& s1, int n) {
        str = s1.substr(0, n);
        return *this;
    }

    Pstring2& mid(const string& s1, int s, int n) {
        if (s >= 0 && s < s1.length()) {
            str = s1.substr(s, n);
        }
        else {
            str = "";
        }
        return *this;
    }

    Pstring2& right(const string& s1, int n) {
        if (n >= 0 && n <= s1.length()) {
            str = s1.substr(s1.length() - n, n);
        }
        else {
            str = "";
        }
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Pstring2 pstr;
    string inputStr;

    cout << "Введите строку: ";
    getline(cin, inputStr);

    pstr.left(inputStr, 5);
    cout << "Левые 5 символов: ";
    pstr.display();

    pstr.mid(inputStr, 3, 4);
    cout << "Символы с 3 по 6 (включительно): ";
    pstr.display();

    pstr.right(inputStr, 4);
    cout << "Правые 4 символа: ";
    pstr.display();

    return 0;
}
