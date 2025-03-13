#include <iostream>
using namespace std;


long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "Rus");

    int hours, minutes, seconds;

    cout << "¬ведите врем€ (часы минуты секунды): ";
    cin >> hours >> minutes >> seconds;

    cout << "ќбщее количество секунд: " << hms_to_secs(hours, minutes, seconds) << endl;

    return 0;
}
