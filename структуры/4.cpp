#include <iostream>
using namespace std;


struct employee{
    int employee_id;  
    float allowance;  
};


int main(){
    setlocale(LC_ALL, "Rus");
    employee emp1, emp2, emp3;  

    cout << "Ââåäèòå äàííûå î ñîòðóäíèêàõ:" << endl;

    cout << "Ñîòðóäíèê 1 - ââåäèòå íîìåð è ïîñîáèå: ";
    cin >> emp1.employee_id >> emp1.allowance;

 
    cout << "Ñîòðóäíèê 2 - ââåäèòå íîìåð è ïîñîáèå: ";
    cin >> emp2.employee_id >> emp2.allowance;

   
    cout << "Ñîòðóäíèê 3 - ââåäèòå íîìåð è ïîñîáèå: ";
    cin >> emp3.employee_id >> emp3.allowance;

   
    cout << "\nÈíôîðìàöèÿ î ñîòðóäíèêàõ:" << endl;

    cout << "Ñîòðóäíèê 1: Íîìåð - " << emp1.employee_id << ", Ïîñîáèå - $" << emp1.allowance << endl;
    cout << "Ñîòðóäíèê 2: Íîìåð - " << emp2.employee_id << ", Ïîñîáèå - $" << emp2.allowance << endl;
    cout << "Ñîòðóäíèê 3: Íîìåð - " << emp3.employee_id << ", Ïîñîáèå - $" << emp3.allowance << endl;

    return 0;
}
