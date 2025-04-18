#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Name {
private:
    string firstName;
    string middleName;
    string lastName;
    unsigned long empNumber;

public:
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

    void display() const {
        cout << "Имя: " << firstName
            << ", Отчество: " << middleName
            << ", Фамилия: " << lastName
            << ", Номер сотрудника: " << empNumber << endl;
    }

    void writeToFile() const {
        ofstream outFile("employees.txt", ios::app); 
        if (!outFile) {
            cerr << "Ошибка при открытии файла для записи!\n";
            return;
        }
        outFile << firstName << ' ' << middleName << ' ' << lastName << ' ' << empNumber << '\n';
        outFile.close();
    }

    bool readFromFile(int recordNum) {
        ifstream inFile("employees.txt");
        if (!inFile) {
            cerr << "Ошибка при открытии файла для чтения!\n";
            return false;
        }

        string f, m, l;
        unsigned long num;
        int current = 1;

        while (inFile >> f >> m >> l >> num) {
            if (current == recordNum) {
                firstName = f;
                middleName = m;
                lastName = l;
                empNumber = num;
                inFile.close();
                return true;
            }
            current++;
        }

        inFile.close();
        return false; 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Name person;
    int choice;

    do {
        cout << "\n1 - Ввести и сохранить сотрудника\n";
        cout << "2 - Прочитать запись по номеру\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Повторите выбор: ";
            cin >> choice;
        }

        if (choice == 1) {
            person.input();
            person.writeToFile();
            cout << "Данные успешно сохранены!\n";
        }
        else if (choice == 2) {
            int recordNum;
            cout << "Введите номер записи (1, 2, 3...): ";
            cin >> recordNum;
            if (person.readFromFile(recordNum)) {
                cout << "\nНайденная запись:\n";
                person.display();
            }
            else {
                cout << "Запись с таким номером не найдена.\n";
            }
        }

    } while (choice != 0);

    cout << "Завершение программы.\n";
    return 0;
}
