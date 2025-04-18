#include <iostream>
#include <limits> 
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    void get_time() {
        while (true) {
            cout << "Введите часы: ";
            cin >> hours;
            if (cin.fail() || hours < 0 || hours > 23) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Значение часов должно лежать между 0 и 23!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Введите минуты: ";
            cin >> minutes;
            if (cin.fail() || minutes < 0 || minutes > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Значение минут должно лежать между 0 и 59!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Введите секунды: ";
            cin >> seconds;
            if (cin.fail() || seconds < 0 || seconds > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Значение секунд должно лежать между 0 и 59!" << endl;
                continue;
            }
            break;
        }
    }
    void put_time() {
        cout << "Время = ";
        cout << hours << ":";
        if (minutes < 10) cout << "0"; 
        cout << minutes << ":";
        if (seconds < 10) cout << "0"; 
        cout << seconds << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Time time;
    char continueInput;

    do {
        time.get_time();  
        time.put_time(); 
        cout << "Хотите продолжить ввод данных? Введите 1 для продолжения или 0 для выхода: ";
        cin >> continueInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continueInput == '1'); 

    cout << "Завершение программы. Спасибо за использование!" << endl;

    return 0;
}
