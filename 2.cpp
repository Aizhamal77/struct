#include <iostream> 
#include <string> 
using namespace std;

class employee{
private:
    string name;
    long number;
public:
    void getdata() {
        cout << "\n������� ���:"; cin >> name;
        cout << "������� �����:"; cin >> number;
    }
    void putdata(){
        cout << "\n ���:" << name;
        cout << "\n �����:" << number;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");

    employee emparr[100]; 
    int n = 0;              
    char ch;               
    do {                   
        cout << "\n������� ������ � ��������� � ������� " << n + 1;
        emparr[n++].getdata();
        cout << "���������� (y/n)?"; cin >> ch;
    } while (ch != 'n');
    for (int j = 0; j < n; j++){
        cout << "\n����� ��������� " << j + 1;
        emparr[j].putdata();
    }
    cout << endl;
    return 0;
}