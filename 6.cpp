#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Name {
private:
    string firstName;
    string middleName;
    string lastName;
    unsigned long empNumber;

public:
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

    void display() const {
        cout << "���: " << firstName
            << ", ��������: " << middleName
            << ", �������: " << lastName
            << ", ����� ����������: " << empNumber << endl;
    }

    void writeToFile() const {
        ofstream outFile("employees.txt", ios::app); 
        if (!outFile) {
            cerr << "������ ��� �������� ����� ��� ������!\n";
            return;
        }
        outFile << firstName << ' ' << middleName << ' ' << lastName << ' ' << empNumber << '\n';
        outFile.close();
    }

    bool readFromFile(int recordNum) {
        ifstream inFile("employees.txt");
        if (!inFile) {
            cerr << "������ ��� �������� ����� ��� ������!\n";
            return false;
        }

        string f, m, l;
        unsigned long num;
        int current = 1;

        while (inFile >> f >> m >> l >> num) {
            if (current == recordNum) {
                firstName = f;
                middleName = m;
                lastName = l;
                empNumber = num;
                inFile.close();
                return true;
            }
            current++;
        }

        inFile.close();
        return false; 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Name person;
    int choice;

    do {
        cout << "\n1 - ������ � ��������� ����������\n";
        cout << "2 - ��������� ������ �� ������\n";
        cout << "0 - �����\n";
        cout << "��� �����: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����. ��������� �����: ";
            cin >> choice;
        }

        if (choice == 1) {
            person.input();
            person.writeToFile();
            cout << "������ ������� ���������!\n";
        }
        else if (choice == 2) {
            int recordNum;
            cout << "������� ����� ������ (1, 2, 3...): ";
            cin >> recordNum;
            if (person.readFromFile(recordNum)) {
                cout << "\n��������� ������:\n";
                person.display();
            }
            else {
                cout << "������ � ����� ������� �� �������.\n";
            }
        }

    } while (choice != 0);

    cout << "���������� ���������.\n";
    return 0;
}
