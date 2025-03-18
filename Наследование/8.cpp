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

    cout << "Ââåäèòå ñòðîêó: ";
    getline(cin, inputStr);

    pstr.left(inputStr, 5);
    cout << "Ëåâûå 5 ñèìâîëîâ: ";
    pstr.display();

    pstr.mid(inputStr, 3, 4);
    cout << "Ñèìâîëû ñ 3 ïî 6 (âêëþ÷èòåëüíî): ";
    pstr.display();

    pstr.right(inputStr, 4);
    cout << "Ïðàâûå 4 ñèìâîëà: ";
    pstr.display();

    return 0;
}
