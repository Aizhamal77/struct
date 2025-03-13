#include <iostream>
#include <string>
using namespace std;


enum Etype { LABORANT, SECRETARY, MANAGER, ENGINEER, CLERK };


class Date {
private:
    int month, day, year;  

public:
    void getDate() {
        char slash;
        cout << "������� ���� ������ �� ������ (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << month << "/" << day << "/" << year;
    }
};

class Employee {
private:
    int empNumber;   
    float salary;  
    Date hireDate;   
    Etype type;    

public:
    Employee() : empNumber(0), salary(0.0f), type(LABORANT) {}

    void getEmploy() {
        int typeChoice;
        cout << "������� ����� ����������: ";
        cin >> empNumber;
        cout << "������� ����� ����������: ";
        cin >> salary;

        hireDate.getDate(); 

        cout << "�������� ��� ���������� (0 - ��������, 1 - ���������, 2 - ��������, 3 - �������, 4 - �����): ";
        cin >> typeChoice;

        switch (typeChoice) {
        case 0: type = LABORANT; break;
        case 1: type = SECRETARY; break;
        case 2: type = MANAGER; break;
        case 3: type = ENGINEER; break;
        case 4: type = CLERK; break;
        default: type = LABORANT; break;
        }
    }

    void putEmploy() const {
        cout << "����� ����������: " << empNumber << endl;
        cout << "����� ����������: " << salary << endl;

        cout << "���� ������ �� ������: ";
        hireDate.showDate(); 

        cout << "\n��� ����������: ";
        switch (type) {
        case LABORANT: cout << "��������"; break;
        case SECRETARY: cout << "���������"; break;
        case MANAGER: cout << "��������"; break;
        case ENGINEER: cout << "�������"; break;
        case CLERK: cout << "�����"; break;
        }
        cout << endl;
    }
};

void inputEmployees(Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\n������� ������ ��� ���������� " << i + 1 << ":\n";
        employees[i].getEmploy();
    }
}

void displayEmployees(const Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\n������ ���������� " << i + 1 << ":\n";
        employees[i].putEmploy();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    const int employeeCount = 3; 
    Employee employees[employeeCount];

    inputEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);

    return 0;
}
