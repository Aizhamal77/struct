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
            cout << "������� ����: ";
            cin >> hours;
            if (cin.fail() || hours < 0 || hours > 23) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "�������� ����� ������ ������ ����� 0 � 23!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "������� ������: ";
            cin >> minutes;
            if (cin.fail() || minutes < 0 || minutes > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "�������� ����� ������ ������ ����� 0 � 59!" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "������� �������: ";
            cin >> seconds;
            if (cin.fail() || seconds < 0 || seconds > 59) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "�������� ������ ������ ������ ����� 0 � 59!" << endl;
                continue;
            }
            break;
        }
    }
    void put_time() {
        cout << "����� = ";
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
        cout << "������ ���������� ���� ������? ������� 1 ��� ����������� ��� 0 ��� ������: ";
        cin >> continueInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continueInput == '1'); 

    cout << "���������� ���������. ������� �� �������������!" << endl;

    return 0;
}
