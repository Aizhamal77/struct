#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class EmpData {
public:
    void run() {
        string firstName, middleName, lastName;
        unsigned long empNum;
        int continueInput = 1;

        ofstream outFile("employees.txt");

        if (!outFile) {
            cerr << "�� ������� ������� ���� ��� ������!" << endl;
            return;
        }

        while (continueInput == 1) {
            cout << "������� ���: ";
            cin >> firstName;
            cout << "������� ��������: ";
            cin >> middleName;
            cout << "������� �������: ";
            cin >> lastName;
            cout << "������� ����� ���������: ";
            cin >> empNum;

            outFile << firstName << " " << middleName << " " << lastName << " " << empNum << endl;

            cout << "������ ������ ������ ��� ������� ����������? (1 � ��, 0 � ���): ";
            cin >> continueInput;

            while (continueInput != 0 && continueInput != 1) {
                cout << "������ �����! ������� 1 ��� ����������� ��� 0 ��� ����������: ";
                cin >> continueInput;
            }
        }

        outFile.close();

        ifstream inFile("employees.txt");

        if (!inFile) {
            cerr << "�� ������� ������� ���� ��� ������!" << endl;
            return;
        }

        string firstNameRead, middleNameRead, lastNameRead;
        unsigned long empNumRead;

        cout << "\n����������� ������ �����������:\n";
        while (inFile >> firstNameRead >> middleNameRead >> lastNameRead >> empNumRead) {
            cout << "���: " << firstNameRead << ", ��������: " << middleNameRead
                << ", �������: " << lastNameRead << ", ����� ���������: " << empNumRead << endl;
        }

        inFile.close();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    EmpData app;
    app.run();
    return 0;
}
