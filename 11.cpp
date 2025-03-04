#include <iostream>
using namespace std;

struct Time {
    int hours;   
    int minutes; 
    int seconds; 
};

int main() {
    setlocale(LC_ALL, "Rus");
    Time t1, t2, result;

    cout << "¬ведите первое врем€ (часы минуты секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "¬ведите второе врем€ (часы минуты секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

 
    long totalSeconds = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds) +
        (t2.hours * 3600 + t2.minutes * 60 + t2.seconds);

 
    result.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    result.minutes = totalSeconds / 60;
    result.seconds = totalSeconds % 60;

 
    cout << "–езультат сложени€ времени: "
        << result.hours << ":"
        << result.minutes << ":"
        << result.seconds << endl;

    return 0;
}
