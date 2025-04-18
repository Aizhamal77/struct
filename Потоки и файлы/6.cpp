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
        cout << "Ââåäèòå èìÿ: ";
        cin >> firstName;
        cout << "Ââåäèòå îò÷åñòâî: ";
        cin >> middleName;
        cout << "Ââåäèòå ôàìèëèþ: ";
        cin >> lastName;
        cout << "Ââåäèòå íîìåð ñîòðóäíèêà: ";
        cin >> empNumber;
    }

    void display() const {
        cout << "Èìÿ: " << firstName
            << ", Îò÷åñòâî: " << middleName
            << ", Ôàìèëèÿ: " << lastName
            << ", Íîìåð ñîòðóäíèêà: " << empNumber << endl;
    }

    void writeToFile() const {
        ofstream outFile("employees.txt", ios::app); 
        if (!outFile) {
            cerr << "Îøèáêà ïðè îòêðûòèè ôàéëà äëÿ çàïèñè!\n";
            return;
        }
        outFile << firstName << ' ' << middleName << ' ' << lastName << ' ' << empNumber << '\n';
        outFile.close();
    }

    bool readFromFile(int recordNum) {
        ifstream inFile("employees.txt");
        if (!inFile) {
            cerr << "Îøèáêà ïðè îòêðûòèè ôàéëà äëÿ ÷òåíèÿ!\n";
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
        cout << "\n1 - Ââåñòè è ñîõðàíèòü ñîòðóäíèêà\n";
        cout << "2 - Ïðî÷èòàòü çàïèñü ïî íîìåðó\n";
        cout << "0 - Âûõîä\n";
        cout << "Âàø âûáîð: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Îøèáêà ââîäà. Ïîâòîðèòå âûáîð: ";
            cin >> choice;
        }

        if (choice == 1) {
            person.input();
            person.writeToFile();
            cout << "Äàííûå óñïåøíî ñîõðàíåíû!\n";
        }
        else if (choice == 2) {
            int recordNum;
            cout << "Ââåäèòå íîìåð çàïèñè (1, 2, 3...): ";
            cin >> recordNum;
            if (person.readFromFile(recordNum)) {
                cout << "\nÍàéäåííàÿ çàïèñü:\n";
                person.display();
            }
            else {
                cout << "Çàïèñü ñ òàêèì íîìåðîì íå íàéäåíà.\n";
            }
        }

    } while (choice != 0);

    cout << "Çàâåðøåíèå ïðîãðàììû.\n";
    return 0;
}
