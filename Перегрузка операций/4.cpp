#include <iostream>
#include <process.h>
using namespace std;

class Int {
private:
    int i;

public:
    Int() : i(0) {}

    Int(int ii) : i(ii) {}

    void putInt() const { cout << i; }

    void getInt() { cin >> i; }

    operator int() const { return i; }

    Int operator +(const Int& i2) const { return checkit(long double(i) + long double(i2)); }

    Int operator -(const Int& i2) const { return checkit(long double(i) - long double(i2)); }

    Int operator *(const Int& i2) const { return checkit(long double(i) * long double(i2)); }

    Int operator /(const Int& i2) const { return checkit(long double(i) / long double(i2)); }

    Int checkit(long double answer) const {
        if (answer > 2147483647.0L || answer < -2147483647.0L) {
            cout << "\nÎøèáêà ïåðåïîëíåíèÿ\n";
            exit(1);
        }
        return Int(int(answer));
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Int alpha = 20;
    Int beta = 7;
    Int delta, gamma;

    gamma = alpha + beta;
    cout << "\ngamma="; gamma.putInt();

    gamma = alpha - beta;
    cout << "\ngamma="; gamma.putInt();

    gamma = alpha * beta;
    cout << "\ngamma="; gamma.putInt();

    gamma = alpha / beta;
    cout << "\ngamma="; gamma.putInt();

    delta = 2147483647;
    gamma = delta + alpha;
    delta = -2147483647;
    gamma = delta - alpha;

    cout << endl;

    return 0;
}
