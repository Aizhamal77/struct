#include <iostream>
#include <string>
using namespace std;


class Date {
private:
    int month;  
    int day;
    int year;  

public:
    Date() : month(0), day(0), year(0) {}  

    void getDate() {
        char slash; 
        cout << "������� ���� � ������� MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << "����: " << month << "/" << day << "/" << year << endl;
    }
};

class Publication {
private:
    string title;  
    float price; 

public:
    void getdata() {
        cout << "\n������� ���������: ";
        cin.ignore();  
        getline(cin, title); 
        cout << "������� ����: ";
        cin >> price;  
    }

    void putdata() const {
        cout << "\n���������: " << title;
        cout << "\n����: " << price;
    }
};


class Publication2 : public Publication {
private:
    Date releaseDate; 

public:
    void getdata() {
        Publication::getdata();
        releaseDate.getDate();  
    }

    void putdata() const {
        Publication::putdata();  
        releaseDate.showDate();  
    }
};

class Book : public Publication2 {
private:
    int pages;  

public:
    void getdata() {
        Publication2::getdata(); 
        cout << "������� ����� �������: ";
        cin >> pages;
    }

    void putdata() const {
        Publication2::putdata(); 
        cout << "\n�������: " << pages;
    }
};

class Tape : public Publication2 {
private:
    float time;  

public:
    void getdata() {
        Publication2::getdata();  
        cout << "������� ����� �������� (� �������): ";
        cin >> time;  
    }

    void putdata() const {
        Publication2::putdata();  
        cout << "\n����� ��������: " << time << " �����";
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
