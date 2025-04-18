#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Name {
private:
    string firstName, middleName, lastName;
    unsigned long empNumber;

    static fstream file; 

public:
    static void openFile() {
        file.open("employees.txt", ios::in | ios::out | ios::app);
        if (!file.is_open()) {
            cerr << "������ �������� �����!\n";
            exit(1);
        }
    }

    static void resetFile() {
        file.clear();
        file.seekg(0); 
    }

    void input() {
        cout << "������� ���: ";
        cin >> firstName;
        cout << "������� ��������: ";
        cin >> middleName;
        cout << "������� �������: ";
        cin >> lastName;
        cout << "������� ����� ����������: ";
        cin >> empNumber;
    }

    void output() const {
        cout << "���: " << firstName
            << ", ��������: " << middleName
            << ", �������: " << lastName
            << ", �����: " << empNumber << endl;
    }

    void write() const {
        file.clear(); 
        file.seekp(0, ios::end); 
        file << firstName << ' ' << middleName << ' ' << lastName << ' ' << empNumber << '\n';
        file.flush(); 
    }

    bool read(int recordNum) {
        resetFile(); 

        string f, m, l;
        unsigned long num;
        int current = 1;

        while (file >> f >> m >> l >> num) {
            if (current == recordNum) {
                firstName = f;
                middleName = m;
                lastName = l;
                empNumber = num;
                return true;
            }
            current++;
        }

        return false; // �� �����
    }

    static void readAll() {
        resetFile();
        string f, m, l;
        unsigned long num;
        int count = 0;

        cout << "\n������ ���� �����������:\n";
        while (file >> f >> m >> l >> num) {
            cout << ++count << ") ���: " << f
                << ", ��������: " << m
                << ", �������: " << l
                << ", �����: " << num << endl;
        }
    }
};

fstream Name::file;

int main() {
    setlocale(LC_ALL, "Rus");
    Name::openFile(); 

    Name person;
    int choice;

    do {
        cout << "\n1 � �������� ����������\n";
        cout << "2 � ��������� ������ �� ������\n";
        cout << "3 � �������� ���� �����������\n";
        cout << "0 � �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�������� ����. ���������: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            person.input();
            person.write();
            cout << "������ ���������.\n";
            break;
        case 2: {
            int num;
            cout << "������� ����� ������: ";
            cin >> num;
            if (person.read(num))
                person.output();
            else
                cout << "������ �� �������.\n";
            break;
        }
        case 3:
            Name::readAll();
            break;
        }

    } while (choice != 0);

    static fstream file; 

    cout << "����������.\n";
    return 0;
}
