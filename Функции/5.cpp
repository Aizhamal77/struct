#include <iostream>
using namespace std;


long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "Rus");

    int hours, minutes, seconds;

    cout << "Ââåäèòå âðåìÿ (÷àñû ìèíóòû ñåêóíäû): ";
    cin >> hours >> minutes >> seconds;

    cout << "Îáùåå êîëè÷åñòâî ñåêóíä: " << hms_to_secs(hours, minutes, seconds) << endl;

    return 0;
}
