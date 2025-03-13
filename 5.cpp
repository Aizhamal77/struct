#include <iostream>
using namespace std;

class Time {
private:
    int hrs, mins, secs;

public:
    Time() : hrs(0), mins(0), secs(0) {}

    Time(int h, int m, int s) : hrs(h), mins(m), secs(s) {}

    void input() {
        cout << "Введите часы: ";
        cin >> hrs;
        cout << "Введите минуты: ";
        cin >> mins;
        cout << "Введите секунды: ";
        cin >> secs;
    }

    void display() const {
        cout << hrs << ":" << mins << ":" << secs;
    }

    Time operator + (const Time& t2) {
        int s = secs + t2.secs;
        int m = mins + t2.mins;
        int h = hrs + t2.hrs;

        if (s > 59) { s -= 60; m++; }
        if (m > 59) { m -= 60; h++; }

        return Time(h, m, s);
    }

    Time operator ++() {
        secs++;
        if (secs > 59) { secs = 0; mins++; }
        if (mins > 59) { mins = 0; hrs++; }

        return *this;
    }

    Time operator ++(int) {
        Time temp = *this;
        secs++;
        if (secs > 59) { secs = 0; mins++; }
        if (mins > 59) { mins = 0; hrs++; }

        return temp;
    }

    Time operator --() {
        secs--;
        if (secs < 0) { secs = 59; mins--; }
        if (mins < 0) { mins = 59; hrs--; }

        return *this;
    }

    Time operator --(int) {
        Time temp = *this;
        secs--;
        if (secs < 0) { secs = 59; mins--; }
        if (mins < 0) { mins = 59; hrs--; }

        return temp;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Time time1, time2, time3;
    time1.input();
    time2.input();

    time3 = time1 + time2;
    cout << "\ntime3 = ";
    time3.display();

    ++time1;
    cout << "\nПосле префиксного инкремента time1: ";
    time1.display();

    time2++;
    cout << "\nПосле постфиксного инкремента time2: ";
    time2.display();

    --time1;
    cout << "\nПосле префиксного декремента time1: ";
    time1.display();

    time3--;
    cout << "\nПосле постфиксного декремента time3: ";
    time3.display();

    cout << endl;
    return 0;
}
