#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };


struct date{
    int day;
    int month;
    int year;
};

struct employee{
    int employee_id;   
    float salary;  
    etype position;   
    date hire_date;  
};


void print_employee(const employee& emp){

    cout << "Íîìåð: " << emp.employee_id << endl;
    cout << "Çàðïëàòà: " << emp.salary << endl;
    cout << "Äîëæíîñòü: ";
    switch (emp.position){
    case laborer: cout << "laborer"; break;
    case secretary: cout << "secretary"; break;
    case manager: cout << "manager"; break;
    case accountant: cout << "accountant"; break;
    case executive: cout << "executive"; break;
    case researcher: cout << "researcher"; break;
    }
    cout << endl;
    cout << "Äàòà ïðèíÿòèÿ íà ðàáîòó: " << emp.hire_date.day << "/"
        << emp.hire_date.month << "/" << emp.hire_date.year << endl;
}

int main(){
    setlocale(LC_ALL, "Rus");
    employee employees[3];  

    for (int i = 0; i < 3; i++){
        cout << "\nÑîòðóäíèê " << i + 1 << ":" << endl;
        cout << "Ââåäèòå íîìåð ñîòðóäíèêà: ";
        cin >> employees[i].employee_id;
        cout << "Ââåäèòå çàðïëàòó ñîòðóäíèêà: ";
        cin >> employees[i].salary;

        cout << "Ââåäèòå äîëæíîñòü (l - laborer, s - secretary, m - manager, a - accountant, e - executive, r - researcher): ";
        char pos;
        cin >> pos;

        switch (pos){
        case 'l': employees[i].position = laborer; break;
        case 's': employees[i].position = secretary; break;
        case 'm': employees[i].position = manager; break;
        case 'a': employees[i].position = accountant; break;
        case 'e': employees[i].position = executive; break;
        case 'r': employees[i].position = researcher; break;
        default: cout << "Íåâåðíàÿ äîëæíîñòü!" << endl; return 1;
        }

        cout << "Ââåäèòå äàòó ïðèíÿòèÿ íà ðàáîòó (ÄÄ ÌÌ ÃÃÃÃ): ";
        cin >> employees[i].hire_date.day >> employees[i].hire_date.month >> employees[i].hire_date.year;
    }

    cout << "\nÈíôîðìàöèÿ î ñîòðóäíèêàõ:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nÑîòðóäíèê " << i + 1 << ":" << endl;
        print_employee(employees[i]);
    }

    return 0;
}
