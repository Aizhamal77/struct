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
            throw invalid_argument("����������� �� ����� ���� �������!");
        }
        reduce();
    }

    // ���������� ���������� ��� ������
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
            throw invalid_argument("������: ������� �� ����.");
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
            throw invalid_argument("����������� �� ����� ���� �������!");
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
                    throw runtime_error("������ �����.");
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
            cout << "������� �������� (+, -, *, /): ";
            cin >> op;
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                return op;
            }
            cout << "������������ ��������. ��������� ����.\n";
        }
    }

    static void performCalc() {
        Frac f1 = inputFraction("������� ������ �����: ");
        char op = inputOperator();
        Frac f2 = inputFraction("������� ������ �����: ");

        try {
            Frac result;
            switch (op) {
            case '+': result = f1 + f2; break;
            case '-': result = f1 - f2; break;
            case '*': result = f1 * f2; break;
            case '/': result = f1 / f2; break;
            }
            cout << "�����: " << result << "\n";
        }
        catch (const exception& e) {
            cout << "������ ��� ����������: " << e.what() << "\n";
        }
    }

    static bool continueCalc() {
        char cont;
        cout << "������� 1 ��� ����������� ��� 0 ��� ������: ";
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

    cout << "������ ���������.\n";
    return 0;
}
