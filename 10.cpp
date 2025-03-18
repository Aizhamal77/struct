#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string id;

public:
    Employee() : name(""), id("") {}

    void input() {
        cout << "������� ��� ����������: ";
        cin >> name;
        cout << "������� ID ����������: ";
        cin >> id;
    }

    void display() const {
        cout << "���: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
protected:
    double salary; 

public:
    Manager() : salary(0.0) {}

    void input() {
        Employee::input();  
        cout << "������� �������� ���������: ";
        cin >> salary;
    }

    void display() const {
        Employee::display(); 
        cout << "�������� ���������: " << salary << endl;
    }
};

class Executive : public Manager {
private:
    double bonus;  
    int shares;    

public:
    Executive() : bonus(0.0), shares(0) {}

    void input() {
        Manager::input(); 
        cout << "������� ������ ������� ������: ";
        cin >> bonus;
        cout << "������� ���������� ����� � ��������: ";
        cin >> shares;
    }

    void display() const {
        Manager::display();  
        cout << "������ ������� ������: " << bonus << endl;
        cout << "���������� �����: " << shares << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Executive exec;

    cout << "������� ������ ��� ������������ (executive):" << endl;
    exec.input();

    cout << "\n������ � ����������� (executive):" << endl;
    exec.display();

    return 0;
}
