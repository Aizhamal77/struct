#include <iostream>
#include <limits> 
using namespace std;

class Frac {
private:
    int num;
    int den; 

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    void reduce() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Frac() : num(0), den(1) {}

    Frac(int n, int d) : num(n), den(d) {
        if (den == 0) {
            throw invalid_argument("Çíàìåíàòåëü íå ìîæåò áûòü íóëåâûì!");
        }
        reduce();
    }

    // Ïåðåãðóçêà îïåðàòîðîâ äëÿ äðîáåé
    Frac operator+(const Frac& f) const {
        return Frac(num * f.den + f.num * den, den * f.den);
    }

    Frac operator-(const Frac& f) const {
        return Frac(num * f.den - f.num * den, den * f.den);
    }

    Frac operator*(const Frac& f) const {
        return Frac(num * f.num, den * f.den);
    }

    Frac operator/(const Frac& f) const {
        if (f.num == 0) {
            throw invalid_argument("Îøèáêà: äåëåíèå íà íîëü.");
        }
        return Frac(num * f.den, den * f.num);
    }

    friend istream& operator>>(istream& in, Frac& f) {
        char slash;
        in >> f.num >> slash >> f.den;

        if (!in || slash != '/') {
            in.setstate(ios::failbit); 
            return in;
        }

        if (f.den == 0) {
            throw invalid_argument("Çíàìåíàòåëü íå ìîæåò áûòü íóëåâûì!");
        }

        f.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Frac& f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

class Calculator {
public:
    static Frac inputFraction(const string& prompt) {
        Frac f;
        while (true) {
            cout << prompt;
            try {
                cin >> f;
                if (cin.fail()) {
                    throw runtime_error("Îøèáêà ââîäà.");
                }
                break;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
        return f;
    }


    static char inputOperator() {
        char op;
        while (true) {
            cout << "Ââåäèòå îïåðàòîð (+, -, *, /): ";
            cin >> op;
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                return op;
            }
            cout << "Íåäîïóñòèìûé îïåðàòîð. Ïîâòîðèòå ââîä.\n";
        }
    }

    static void performCalc() {
        Frac f1 = inputFraction("Ââåäèòå ïåðâóþ äðîáü: ");
        char op = inputOperator();
        Frac f2 = inputFraction("Ââåäèòå âòîðóþ äðîáü: ");

        try {
            Frac result;
            switch (op) {
            case '+': result = f1 + f2; break;
            case '-': result = f1 - f2; break;
            case '*': result = f1 * f2; break;
            case '/': result = f1 / f2; break;
            }
            cout << "Îòâåò: " << result << "\n";
        }
        catch (const exception& e) {
            cout << "Îøèáêà ïðè âû÷èñëåíèè: " << e.what() << "\n";
        }
    }

    static bool continueCalc() {
        char cont;
        cout << "Ââåäèòå 1 äëÿ ïðîäîëæåíèÿ èëè 0 äëÿ âûõîäà: ";
        cin >> cont;
        return cont == '1';
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    bool continueProgram = true;

    while (continueProgram) {
        Calculator::performCalc();
        continueProgram = Calculator::continueCalc();
    }

    cout << "Ðàáîòà çàâåðøåíà.\n";
    return 0;
}
