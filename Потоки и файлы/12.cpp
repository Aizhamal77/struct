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
        cout << "Èìÿ: " << firstName << ", Îò÷åñòâî: " << middleName
            << ", Ôàìèëèÿ: " << lastName << ", Íîìåð ðàáîòíèêà: " << employeeNumber << endl;
    }

    static void findEmployeeByNumber(const string& filename, unsigned long employeeNumber) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Íå óäàëîñü îòêðûòü ôàéë!" << endl;
            return;
        }

        Employee emp;
        bool found = false;
        while (inFile >> emp.firstName >> emp.middleName >> emp.lastName >> emp.employeeNumber) {
            if (emp.employeeNumber == employeeNumber) {
                cout << "Ñîòðóäíèê íàéäåí: " << endl;
                emp.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Ñîòðóäíèê ñ íîìåðîì " << employeeNumber << " íå íàéäåí." << endl;
        }

        inFile.close();
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cerr << "Íå óäàëîñü îòêðûòü ôàéë äëÿ çàïèñè!" << endl;
            return;
        }
        outFile << firstName << " " << middleName << " " << lastName << " " << employeeNumber << endl;
        outFile.close();
    }
};

void displayMenu() {
    cout << "Âûáåðèòå äåéñòâèå:" << endl;
    cout << "1. Äîáàâèòü ñîòðóäíèêà" << endl;
    cout << "2. Íàéòè ñîòðóäíèêà ïî íîìåðó (íàæìèòå 'f')" << endl;
    cout << "0. Âûõîä" << endl;
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
            cout << "Ââåäèòå èìÿ ñîòðóäíèêà: ";
            cin >> emp.firstName;
            cout << "Ââåäèòå îò÷åñòâî ñîòðóäíèêà: ";
            cin >> emp.middleName;
            cout << "Ââåäèòå ôàìèëèþ ñîòðóäíèêà: ";
            cin >> emp.lastName;
            cout << "Ââåäèòå íîìåð ðàáîòíèêà: ";
            cin >> emp.employeeNumber;

            emp.saveToFile(filename);
            cout << "Ñîòðóäíèê äîáàâëåí!" << endl;

        }
        else if (option == 'f' || option == 'F') {
            unsigned long searchNumber;
            cout << "Ââåäèòå íîìåð ðàáîòíèêà äëÿ ïîèñêà: ";
            cin >> searchNumber;

            Employee::findEmployeeByNumber(filename, searchNumber);
        }
        else if (option == '0') {
            break;
        }
        else {
            cout << "Íåâåðíûé âûáîð, ïîïðîáóéòå ñíîâà." << endl;
        }
    }

    return 0;
}
