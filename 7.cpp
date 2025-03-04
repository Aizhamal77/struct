#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };


struct date{
    int day;
    int month;
    int year;
};

struct employee{
    int employee_id;   
    float salary;  
    etype position;   
    date hire_date;  
};


void print_employee(const employee& emp){

    cout << "�����: " << emp.employee_id << endl;
    cout << "��������: " << emp.salary << endl;
    cout << "���������: ";
    switch (emp.position){
    case laborer: cout << "laborer"; break;
    case secretary: cout << "secretary"; break;
    case manager: cout << "manager"; break;
    case accountant: cout << "accountant"; break;
    case executive: cout << "executive"; break;
    case researcher: cout << "researcher"; break;
    }
    cout << endl;
    cout << "���� �������� �� ������: " << emp.hire_date.day << "/"
        << emp.hire_date.month << "/" << emp.hire_date.year << endl;
}

int main(){
    setlocale(LC_ALL, "Rus");
    employee employees[3];  

    for (int i = 0; i < 3; i++){
        cout << "\n��������� " << i + 1 << ":" << endl;
        cout << "������� ����� ����������: ";
        cin >> employees[i].employee_id;
        cout << "������� �������� ����������: ";
        cin >> employees[i].salary;

        cout << "������� ��������� (l - laborer, s - secretary, m - manager, a - accountant, e - executive, r - researcher): ";
        char pos;
        cin >> pos;

        switch (pos){
        case 'l': employees[i].position = laborer; break;
        case 's': employees[i].position = secretary; break;
        case 'm': employees[i].position = manager; break;
        case 'a': employees[i].position = accountant; break;
        case 'e': employees[i].position = executive; break;
        case 'r': employees[i].position = researcher; break;
        default: cout << "�������� ���������!" << endl; return 1;
        }

        cout << "������� ���� �������� �� ������ (�� �� ����): ";
        cin >> employees[i].hire_date.day >> employees[i].hire_date.month >> employees[i].hire_date.year;
    }

    cout << "\n���������� � �����������:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\n��������� " << i + 1 << ":" << endl;
        print_employee(employees[i]);
    }

    return 0;
}
