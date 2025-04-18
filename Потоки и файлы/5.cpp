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
            cout << "Ââåäèòå ÷àñû: ";
            cin >> hours;
            if (cin.fail() || hours < 0 || hours > 23) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Çíà÷åíèå ÷àñîâ äîëæíî ëåæàòü ìåæäó 0 è 23!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Ââåäèòå ìèíóòû: ";
            cin >> minutes;
            if (cin.fail() || minutes < 0 || minutes > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Çíà÷åíèå ìèíóò äîëæíî ëåæàòü ìåæäó 0 è 59!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Ââåäèòå ñåêóíäû: ";
            cin >> seconds;
            if (cin.fail() || seconds < 0 || seconds > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Çíà÷åíèå ñåêóíä äîëæíî ëåæàòü ìåæäó 0 è 59!" << endl;
                continue;
            }
            break;
        }
    }
    void put_time() {
        cout << "Âðåìÿ = ";
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
        cout << "Õîòèòå ïðîäîëæèòü ââîä äàííûõ? Ââåäèòå 1 äëÿ ïðîäîëæåíèÿ èëè 0 äëÿ âûõîäà: ";
        cin >> continueInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continueInput == '1'); 

    cout << "Çàâåðøåíèå ïðîãðàììû. Ñïàñèáî çà èñïîëüçîâàíèå!" << endl;

    return 0;
}
