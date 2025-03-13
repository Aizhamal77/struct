#include <iostream>
#include <string>
using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cout << "\n������� ���������: ";
        getline(cin, title);  
        cout << "������� ����: ";
        cin >> price;
        cin.ignore(); 
    }

    void putdata() const {
        cout << "\n���������: " << title;
        cout << "\n����: " << price;
    }
};

class Book : private Publication {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "������� ����� �������: ";
        cin >> pages;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\n�������: " << pages;
    }
};

class Tape : private Publication {
private:
    float time;

public:
    void getdata() {
        Publication::getdata();
        cout << "������� ����� ��������: ";
        cin >> time;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\n����� ��������: " << time;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Book book1;  
    Tape tape1;

    cout << "������� ������ ��� �����:\n";
    book1.getdata(); 

    cout << "\n������� ������ ��� ������������:\n";
    tape1.getdata();   

    cout << "\n������ � �����:\n";
    book1.putdata();   

    cout << "\n������ �� ������������:\n";
    tape1.putdata();   

    return 0;
}
