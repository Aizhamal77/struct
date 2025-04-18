#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class EmpData {
public:
    void run() {
        string firstName, middleName, lastName;
        unsigned long empNum;
        int continueInput = 1;

        ofstream outFile("employees.txt");

        if (!outFile) {
            cerr << "Не удалось открыть файл для записи!" << endl;
            return;
        }

        while (continueInput == 1) {
            cout << "Введите имя: ";
            cin >> firstName;
            cout << "Введите отчество: ";
            cin >> middleName;
            cout << "Введите фамилию: ";
            cin >> lastName;
            cout << "Введите номер работника: ";
            cin >> empNum;

            outFile << firstName << " " << middleName << " " << lastName << " " << empNum << endl;

            cout << "Хотите ввести данные для другого сотрудника? (1 — да, 0 — нет): ";
            cin >> continueInput;

            while (continueInput != 0 && continueInput != 1) {
                cout << "Ошибка ввода! Введите 1 для продолжения или 0 для завершения: ";
                cin >> continueInput;
            }
        }

        outFile.close();

        ifstream inFile("employees.txt");

        if (!inFile) {
            cerr << "Не удалось открыть файл для чтения!" << endl;
            return;
        }

        string firstNameRead, middleNameRead, lastNameRead;
        unsigned long empNumRead;

        cout << "\nСохраненные данные сотрудников:\n";
        while (inFile >> firstNameRead >> middleNameRead >> lastNameRead >> empNumRead) {
            cout << "Имя: " << firstNameRead << ", Отчество: " << middleNameRead
                << ", Фамилия: " << lastNameRead << ", Номер работника: " << empNumRead << endl;
        }

        inFile.close();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    EmpData app;
    app.run();
    return 0;
}
