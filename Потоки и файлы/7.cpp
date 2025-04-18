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
            cerr << "Îøèáêà îòêðûòèÿ ôàéëà!\n";
            exit(1);
        }
    }

    static void resetFile() {
        file.clear();
        file.seekg(0); 
    }

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

    void output() const {
        cout << "Èìÿ: " << firstName
            << ", Îò÷åñòâî: " << middleName
            << ", Ôàìèëèÿ: " << lastName
            << ", Íîìåð: " << empNumber << endl;
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

        return false; // íå íàøëè
    }

    static void readAll() {
        resetFile();
        string f, m, l;
        unsigned long num;
        int count = 0;

        cout << "\nÑïèñîê âñåõ ñîòðóäíèêîâ:\n";
        while (file >> f >> m >> l >> num) {
            cout << ++count << ") Èìÿ: " << f
                << ", Îò÷åñòâî: " << m
                << ", Ôàìèëèÿ: " << l
                << ", Íîìåð: " << num << endl;
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
        cout << "\n1 — Äîáàâèòü ñîòðóäíèêà\n";
        cout << "2 — Ïðî÷èòàòü çàïèñü ïî íîìåðó\n";
        cout << "3 — Ïîêàçàòü âñåõ ñîòðóäíèêîâ\n";
        cout << "0 — Âûõîä\n";
        cout << "Âûáåðèòå äåéñòâèå: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Íåâåðíûé ââîä. Ïîâòîðèòå: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            person.input();
            person.write();
            cout << "Äàííûå ñîõðàíåíû.\n";
            break;
        case 2: {
            int num;
            cout << "Ââåäèòå íîìåð çàïèñè: ";
            cin >> num;
            if (person.read(num))
                person.output();
            else
                cout << "Çàïèñü íå íàéäåíà.\n";
            break;
        }
        case 3:
            Name::readAll();
            break;
        }

    } while (choice != 0);

    static fstream file; 

    cout << "Çàâåðøåíèå.\n";
    return 0;
}
