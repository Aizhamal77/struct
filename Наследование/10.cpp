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
        cout << "Ââåäèòå èìÿ ñîòðóäíèêà: ";
        cin >> name;
        cout << "Ââåäèòå ID ñîòðóäíèêà: ";
        cin >> id;
    }

    void display() const {
        cout << "Èìÿ: " << name << endl;
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
        cout << "Ââåäèòå çàðïëàòó ìåíåäæåðà: ";
        cin >> salary;
    }

    void display() const {
        Employee::display(); 
        cout << "Çàðïëàòà ìåíåäæåðà: " << salary << endl;
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
        cout << "Ââåäèòå ðàçìåð ãîäîâîé ïðåìèè: ";
        cin >> bonus;
        cout << "Ââåäèòå êîëè÷åñòâî àêöèé â êîìïàíèè: ";
        cin >> shares;
    }

    void display() const {
        Manager::display();  
        cout << "Ðàçìåð ãîäîâîé ïðåìèè: " << bonus << endl;
        cout << "Êîëè÷åñòâî àêöèé: " << shares << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Executive exec;

    cout << "Ââåäèòå äàííûå äëÿ óïðàâëÿþùåãî (executive):" << endl;
    exec.input();

    cout << "\nÄàííûå î óïðàâëÿþùåì (executive):" << endl;
    exec.display();

    return 0;
}
