#include <iostream>
using namespace std;


struct employee{
    int employee_id;  
    float allowance;  
};


int main(){
    setlocale(LC_ALL, "Rus");
    employee emp1, emp2, emp3;  

    cout << "������� ������ � �����������:" << endl;

    cout << "��������� 1 - ������� ����� � �������: ";
    cin >> emp1.employee_id >> emp1.allowance;

 
    cout << "��������� 2 - ������� ����� � �������: ";
    cin >> emp2.employee_id >> emp2.allowance;

   
    cout << "��������� 3 - ������� ����� � �������: ";
    cin >> emp3.employee_id >> emp3.allowance;

   
    cout << "\n���������� � �����������:" << endl;

    cout << "��������� 1: ����� - " << emp1.employee_id << ", ������� - $" << emp1.allowance << endl;
    cout << "��������� 2: ����� - " << emp2.employee_id << ", ������� - $" << emp2.allowance << endl;
    cout << "��������� 3: ����� - " << emp3.employee_id << ", ������� - $" << emp3.allowance << endl;

    return 0;
}
