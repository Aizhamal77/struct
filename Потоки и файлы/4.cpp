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
            cerr << "Íĺ óäŕëîńü îňęđűňü ôŕéë äë˙ çŕďčńč!" << endl;
            return;
        }

        while (continueInput == 1) {
            cout << "Ââĺäčňĺ čě˙: ";
            cin >> firstName;
            cout << "Ââĺäčňĺ îň÷ĺńňâî: ";
            cin >> middleName;
            cout << "Ââĺäčňĺ ôŕěčëčţ: ";
            cin >> lastName;
            cout << "Ââĺäčňĺ íîěĺđ đŕáîňíčęŕ: ";
            cin >> empNum;

            outFile << firstName << " " << middleName << " " << lastName << " " << empNum << endl;

            cout << "Őîňčňĺ ââĺńňč äŕííűĺ äë˙ äđóăîăî ńîňđóäíčęŕ? (1 — äŕ, 0 — íĺň): ";
            cin >> continueInput;

            while (continueInput != 0 && continueInput != 1) {
                cout << "Îřčáęŕ ââîäŕ! Ââĺäčňĺ 1 äë˙ ďđîäîëćĺíč˙ čëč 0 äë˙ çŕâĺđřĺíč˙: ";
                cin >> continueInput;
            }
        }

        outFile.close();

        ifstream inFile("employees.txt");

        if (!inFile) {
            cerr << "Íĺ óäŕëîńü îňęđűňü ôŕéë äë˙ ÷ňĺíč˙!" << endl;
            return;
        }

        string firstNameRead, middleNameRead, lastNameRead;
        unsigned long empNumRead;

        cout << "\nŃîőđŕíĺííűĺ äŕííűĺ ńîňđóäíčęîâ:\n";
        while (inFile >> firstNameRead >> middleNameRead >> lastNameRead >> empNumRead) {
            cout << "Čě˙: " << firstNameRead << ", Îň÷ĺńňâî: " << middleNameRead
                << ", Ôŕěčëč˙: " << lastNameRead << ", Íîěĺđ đŕáîňíčęŕ: " << empNumRead << endl;
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
