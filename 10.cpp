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
        cout << "Введите имя сотрудника: ";
        cin >> name;
        cout << "Введите ID сотрудника: ";
        cin >> id;
    }

    void display() const {
        cout << "Имя: " << name << endl;
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
        cout << "Введите зарплату менеджера: ";
        cin >> salary;
    }

    void display() const {
        Employee::display(); 
        cout << "Зарплата менеджера: " << salary << endl;
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
        cout << "Введите размер годовой премии: ";
        cin >> bonus;
        cout << "Введите количество акций в компании: ";
        cin >> shares;
    }

    void display() const {
        Manager::display();  
        cout << "Размер годовой премии: " << bonus << endl;
        cout << "Количество акций: " << shares << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Executive exec;

    cout << "Введите данные для управляющего (executive):" << endl;
    exec.input();

    cout << "\nДанные о управляющем (executive):" << endl;
    exec.display();

    return 0;
}
