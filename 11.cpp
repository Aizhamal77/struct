#include <iostream>
using namespace std;


struct sterling {
    int pounds;  
    int shillings;  
    int pence; 
};

sterling getSterling() {
    sterling amount;
    cout << "������� ���������� ������: ";
    cin >> amount.pounds;
    cout << "������� ���������� ���������: ";
    cin >> amount.shillings;
    cout << "������� ���������� ������: ";
    cin >> amount.pence;
    return amount;
}


sterling addSterling(const sterling& s1, const sterling& s2) {
    sterling result;
    result.pence = s1.pence + s2.pence;
    result.shillings = s1.shillings + s2.shillings + result.pence / 12;  
    result.pounds = s1.pounds + s2.pounds + result.shillings / 20; 

    result.pence = result.pence % 12;
    result.shillings = result.shillings % 20;

    return result;
}


void printSterling(const sterling& amount) {
    cout << amount.pounds << " ������, " << amount.shillings << " ���������, " << amount.pence << " ������." << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "������� ������ �������� �����:" << endl;
    sterling s1 = getSterling();

    cout << "������� ������ �������� �����:" << endl;
    sterling s2 = getSterling();

    sterling result = addSterling(s1, s2);

    cout << "��������� ��������: ";
    printSterling(result);

    return 0;
}
