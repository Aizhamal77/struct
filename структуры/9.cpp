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

    cout << "Ââåäèòå êîëè÷åñòâî ÷àñîâ: ";
    cin >> t1.hours;

    cout << "Ââåäèòå êîëè÷åñòâî ìèíóò: ";
    cin >> t1.minutes;

    cout << "Ââåäèòå êîëè÷åñòâî ñåêóíä: ";
    cin >> t1.seconds;

   
    long totalSecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

    cout << "Îáùåå êîëè÷åñòâî ñåêóíä: " << totalSecs << endl;

    return 0;
}
