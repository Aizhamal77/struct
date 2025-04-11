#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;  
    float salary; 

public:
    Person(string n = "", float s = 0.0f) : name(n), salary(s) {}

    void setData(string n, float s) {
        name = n;
        salary = s;
    }

    void printData() const {
        cout << "Имя: " << name << ", Зарплата: " << salary << endl;
    }

    float getSalary() const {
        return salary;
    }

    string getName() const {
        return name;
    }
};

void salsort(Person* persPtr[], int size) {
    for (int j = 0; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
            if ((*(persPtr + j))->getSalary() > (*(persPtr + k))->getSalary()) {
                // Обмен указателями
                Person* temp = *(persPtr + j);
                *(persPtr + j) = *(persPtr + k);
                *(persPtr + k) = temp;
            }
        }
    }
}

class PersonList {
private:
    Person* persPtr[3]; 
    int size;

public:
    PersonList(int s) : size(s) {}

    void input() {
        string name;
        float salary;

        for (int i = 0; i < size; i++) {
            cout << "Введите имя человека " << (i + 1) << ": ";
            cin >> name;
            cout << "Введите зарплату для " << name << ": ";
            cin >> salary;

            persPtr[i] = new Person(name, salary);
        }
    }

    void output() const {
        cout << "\nДанные сотрудников:\n";
        for (int i = 0; i < size; i++) {
            persPtr[i]->printData();
        }
    }

    void sortBySalary() {
        salsort(persPtr, size);
    }

    void osvb() {
        for (int i = 0; i < size; i++) {
            delete persPtr[i];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    PersonList list(3);
    list.input();      
    list.output();   

    list.sortBySalary(); 
    cout << "\nПосле сортировки:\n";
    list.output();     

    list.osvb(); 
    return 0;
}
