#include <iostream>
using namespace std;

struct Time {
    int hours;   
    int minutes; 
    int seconds; 
};

int main() {
    setlocale(LC_ALL, "Rus");
   
    Time t1;

    cout << "¬ведите количество часов: ";
    cin >> t1.hours;

    cout << "¬ведите количество минут: ";
    cin >> t1.minutes;

    cout << "¬ведите количество секунд: ";
    cin >> t1.seconds;

   
    long totalSecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

    cout << "ќбщее количество секунд: " << totalSecs << endl;

    return 0;
}
