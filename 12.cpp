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
        cout << "Имя: " << firstName << ", Отчество: " << middleName
            << ", Фамилия: " << lastName << ", Номер работника: " << employeeNumber << endl;
    }

    static void findEmployeeByNumber(const string& filename, unsigned long employeeNumber) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Не удалось открыть файл!" << endl;
            return;
        }

        Employee emp;
        bool found = false;
        while (inFile >> emp.firstName >> emp.middleName >> emp.lastName >> emp.employeeNumber) {
            if (emp.employeeNumber == employeeNumber) {
                cout << "Сотрудник найден: " << endl;
                emp.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Сотрудник с номером " << employeeNumber << " не найден." << endl;
        }

        inFile.close();
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cerr << "Не удалось открыть файл для записи!" << endl;
            return;
        }
        outFile << firstName << " " << middleName << " " << lastName << " " << employeeNumber << endl;
        outFile.close();
    }
};

void displayMenu() {
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить сотрудника" << endl;
    cout << "2. Найти сотрудника по номеру (нажмите 'f')" << endl;
    cout << "0. Выход" << endl;
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
            cout << "Введите имя сотрудника: ";
            cin >> emp.firstName;
            cout << "Введите отчество сотрудника: ";
            cin >> emp.middleName;
            cout << "Введите фамилию сотрудника: ";
            cin >> emp.lastName;
            cout << "Введите номер работника: ";
            cin >> emp.employeeNumber;

            emp.saveToFile(filename);
            cout << "Сотрудник добавлен!" << endl;

        }
        else if (option == 'f' || option == 'F') {
            unsigned long searchNumber;
            cout << "Введите номер работника для поиска: ";
            cin >> searchNumber;

            Employee::findEmployeeByNumber(filename, searchNumber);
        }
        else if (option == '0') {
            break;
        }
        else {
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }

    return 0;
}
