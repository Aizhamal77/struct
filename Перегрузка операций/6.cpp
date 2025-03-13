#include <iostream>
using namespace std;

class Time {
private:
    int hrs, mins, secs;

public:
    Time() : hrs(0), mins(0), secs(0) {}

    Time(int h, int m, int s) : hrs(h), mins(m), secs(s) {}

    void setTime(int h, int m, int s) {
        hrs = h;
        mins = m;
        secs = s;
    }

    void getTime() const {
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

    Time operator - (const Time& t2) {
        int s = secs - t2.secs;
        int m = mins - t2.mins;
        int h = hrs - t2.hrs;

        if (s < 0) { s += 60; m--; }
        if (m < 0) { m += 60; h--; }

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

    Time operator * (float multiplier) {
        int totalSeconds = (hrs * 3600 + mins * 60 + secs) * multiplier;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    int h1, m1, s1, h2, m2, s2;

    cout << "Ââåäèòå ïåðâîå âðåìÿ (÷àñû, ìèíóòû, ñåêóíäû): ";
    cin >> h1 >> m1 >> s1;

    cout << "Ââåäèòå âòîðîå âðåìÿ (÷àñû, ìèíóòû, ñåêóíäû): ";
    cin >> h2 >> m2 >> s2;

    Time time1(h1, m1, s1);
    Time time2(h2, m2, s2);

    Time time3 = time1 + time2;
    cout << "\nÑëîæåíèå: ";
    time3.getTime();

    time3 = time1 - time2;
    cout << "\nÂû÷èòàíèå: ";
    time3.getTime();

    time3 = time1 * 2.5;  
    cout << "\nÓìíîæåíèå íà 2.5: ";
    time3.getTime();

    cout << endl;
    return 0;
}
