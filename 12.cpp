#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
public:
    string firstName;
    string middleName;
    string lastName;
    unsigned long employeeNumber;

    void display() const {
        cout << "���: " << firstName << ", ��������: " << middleName
            << ", �������: " << lastName << ", ����� ���������: " << employeeNumber << endl;
    }

    static void findEmployeeByNumber(const string& filename, unsigned long employeeNumber) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "�� ������� ������� ����!" << endl;
            return;
        }

        Employee emp;
        bool found = false;
        while (inFile >> emp.firstName >> emp.middleName >> emp.lastName >> emp.employeeNumber) {
            if (emp.employeeNumber == employeeNumber) {
                cout << "��������� ������: " << endl;
                emp.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "��������� � ������� " << employeeNumber << " �� ������." << endl;
        }

        inFile.close();
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cerr << "�� ������� ������� ���� ��� ������!" << endl;
            return;
        }
        outFile << firstName << " " << middleName << " " << lastName << " " << employeeNumber << endl;
        outFile.close();
    }
};

void displayMenu() {
    cout << "�������� ��������:" << endl;
    cout << "1. �������� ����������" << endl;
    cout << "2. ����� ���������� �� ������ (������� 'f')" << endl;
    cout << "0. �����" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    string filename = "employees.txt";
    Employee emp;
    char option;

    while (true) {
        displayMenu();
        cin >> option;

        if (option == '1') {
            cout << "������� ��� ����������: ";
            cin >> emp.firstName;
            cout << "������� �������� ����������: ";
            cin >> emp.middleName;
            cout << "������� ������� ����������: ";
            cin >> emp.lastName;
            cout << "������� ����� ���������: ";
            cin >> emp.employeeNumber;

            emp.saveToFile(filename);
            cout << "��������� ��������!" << endl;

        }
        else if (option == 'f' || option == 'F') {
            unsigned long searchNumber;
            cout << "������� ����� ��������� ��� ������: ";
            cin >> searchNumber;

            Employee::findEmployeeByNumber(filename, searchNumber);
        }
        else if (option == '0') {
            break;
        }
        else {
            cout << "�������� �����, ���������� �����." << endl;
        }
    }

    return 0;
}
