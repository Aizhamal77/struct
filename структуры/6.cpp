#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    setlocale(LC_ALL, "Rus");
    char first_letter;  
    etype position;    

   
    cout << "Ââåäèòå ïåðâóþ áóêâó äîëæíîñòè (laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;

    switch (first_letter) {
    case 'l':
    case 'L': position = laborer; break;
    case 's':
    case 'S': position = secretary; break;
    case 'm':
    case 'M': position = manager; break;
    case 'a':
    case 'A': position = accountant; break;
    case 'e':
    case 'E': position = executive; break;
    case 'r':
    case 'R': position = researcher; break;
    default:
        cout << "Íåâåðíàÿ ïåðâàÿ áóêâà!" << endl;
        return 1;  
    }

    cout << "Ïîëíîå íàçâàíèå äîëæíîñòè: ";

    switch (position) {
    case laborer: cout << "laborer"; break;
    case secretary: cout << "secretary"; break;
    case manager: cout << "manager"; break;
    case accountant: cout << "accountant"; break;
    case executive: cout << "executive"; break;
    case researcher: cout << "researcher"; break;
    }

    cout << endl;
    return 0;
}
