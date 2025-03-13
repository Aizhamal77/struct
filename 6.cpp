#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(const Time& t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long total_seconds) {
    Time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
}

int main() {
    Time t1, t2, result;

    cout << "¬ведите врем€ 1 (часы минуты секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "¬ведите врем€ 2 (часы минуты секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    long secs1 = time_to_secs(t1);
    long secs2 = time_to_secs(t2);
    long total_secs = secs1 + secs2;

    result = secs_to_time(total_secs);

    cout << "–езультат (часы:минуты:секунды): "
        << result.hours << ":"
        << result.minutes << ":"
        << result.seconds << endl;

    return 0;
}
