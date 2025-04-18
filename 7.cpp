#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Name {
private:
    string firstName, middleName, lastName;
    unsigned long empNumber;

    static fstream file; 

public:
    static void openFile() {
        file.open("employees.txt", ios::in | ios::out | ios::app);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла!\n";
            exit(1);
        }
    }

    static void resetFile() {
        file.clear();
        file.seekg(0); 
    }

    void input() {
        cout << "Введите имя: ";
        cin >> firstName;
        cout << "Введите отчество: ";
        cin >> middleName;
        cout << "Введите фамилию: ";
        cin >> lastName;
        cout << "Введите номер сотрудника: ";
        cin >> empNumber;
    }

    void output() const {
        cout << "Имя: " << firstName
            << ", Отчество: " << middleName
            << ", Фамилия: " << lastName
            << ", Номер: " << empNumber << endl;
    }

    void write() const {
        file.clear(); 
        file.seekp(0, ios::end); 
        file << firstName << ' ' << middleName << ' ' << lastName << ' ' << empNumber << '\n';
        file.flush(); 
    }

    bool read(int recordNum) {
        resetFile(); 

        string f, m, l;
        unsigned long num;
        int current = 1;

        while (file >> f >> m >> l >> num) {
            if (current == recordNum) {
                firstName = f;
                middleName = m;
                lastName = l;
                empNumber = num;
                return true;
            }
            current++;
        }

        return false; // не нашли
    }

    static void readAll() {
        resetFile();
        string f, m, l;
        unsigned long num;
        int count = 0;

        cout << "\nСписок всех сотрудников:\n";
        while (file >> f >> m >> l >> num) {
            cout << ++count << ") Имя: " << f
                << ", Отчество: " << m
                << ", Фамилия: " << l
                << ", Номер: " << num << endl;
        }
    }
};

fstream Name::file;

int main() {
    setlocale(LC_ALL, "Rus");
    Name::openFile(); 

    Name person;
    int choice;

    do {
        cout << "\n1 — Добавить сотрудника\n";
        cout << "2 — Прочитать запись по номеру\n";
        cout << "3 — Показать всех сотрудников\n";
        cout << "0 — Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Повторите: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            person.input();
            person.write();
            cout << "Данные сохранены.\n";
            break;
        case 2: {
            int num;
            cout << "Введите номер записи: ";
            cin >> num;
            if (person.read(num))
                person.output();
            else
                cout << "Запись не найдена.\n";
            break;
        }
        case 3:
            Name::readAll();
            break;
        }

    } while (choice != 0);

    static fstream file; 

    cout << "Завершение.\n";
    return 0;
}
