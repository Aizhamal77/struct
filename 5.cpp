#include <iostream>
#include <string>
using namespace std;

class employee {  
protected:
    string name;
    string number;

public:
    void getdata() {
        cout << "\n������� ���: ";
        cin >> name;
        cout << "������� ����� ����������: ";
        cin >> number;
    }

    void putdata() const {
        cout << "\n���: " << name;
        cout << "\n�����: " << number;
    }
};

enum PaymentPeriod { Hourly, Weekly, Monthly };  

class employee2 : public employee { 
protected:
    double compensation;
    PaymentPeriod period;

public:
    void getdata() {
        employee::getdata();
        cout << "������� �����������: ";
        cin >> compensation;
        char p;
        cout << "������� ������ ������ (h - ���������, w - �����������, m - ����������): ";
        cin >> p;
        if (p == 'h' || p == 'H') {
            period = Hourly;
        }
        else if (p == 'w' || p == 'W') {
            period = Weekly;
        }
        else if (p == 'm' || p == 'M') {
            period = Monthly;
        }
        else {
            cout << "�������� �����. ���������� ������ ������ �� ��������� - ���������.\n";
            period = Hourly;
        }
    }

    void putdata() const {
        employee::putdata();
        cout << "\n�����������: " << compensation;
        cout << "\n������ ������: ";
        if (period == Hourly) {
            cout << "���������";
        }
        else if (period == Weekly) {
            cout << "�����������";
        }
        else if (period == Monthly) {
            cout << "����������";
        }
    }
};

class laborer2 : public employee2 {  
private:
    string jobTitle;

public:
    void getdata() {
        employee2::getdata();
        cout << "������� ��������� ��������: ";
        cin >> jobTitle;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\n��������� ��������: " << jobTitle;
    }
};

class manager2 : public employee2 { 
private:
    string department;

public:
    void getdata() {
        employee2::getdata();
        cout << "������� ����������� ���������: ";
        cin >> department;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\n����������� ���������: " << department;
    }
};

class scientist2 : public employee2 {  
private:
    string researchField;

public:
    void getdata() {
        employee2::getdata();
        cout << "������� ������� ������������ �������: ";
        cin >> researchField;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\n������� ������������: " << researchField;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    laborer2 laborer;
    manager2 manager;
    scientist2 scientist;

    cout << "\n������ ��������:\n";
    laborer.getdata();
    laborer.putdata();

    cout << "\n\n������ ���������:\n";
    manager.getdata();
    manager.putdata();

    cout << "\n\n������ �������:\n";
    scientist.getdata();
    scientist.putdata();

    cout << endl;
    return 0;
}
