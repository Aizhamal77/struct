#include <iostream>
using namespace std;

class Employee {
private:
    int empNumber;   
    float salary;   

public:
   
    Employee() : empNumber(0), salary(0.0f) {}

    void inputData() {
        cout << "������� ����� ����������: ";
        cin >> empNumber;
        cout << "������� ����� ����������: ";
        cin >> salary;
    }

  
    void displayData() const {
        cout << "����� ����������: " << empNumber << endl;
        cout << "����� ����������: " << salary << endl;
    }
};


void inputEmployees(Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        cout << "������� ������ ��� ���������� " << i + 1 << ":\n";
        emp[i].inputData();
    }
}


void displayEmployees(const Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\n������ ���������� " << i + 1 << ":\n";
        emp[i].displayData();
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
