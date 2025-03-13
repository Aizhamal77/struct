#include <iostream>
#include <string>
using namespace std;

class employee {  
protected:
    string name;
    string number;

public:
    void getdata() {
        cout << "\nВведите имя: ";
        cin >> name;
        cout << "Введите номер сотрудника: ";
        cin >> number;
    }

    void putdata() const {
        cout << "\nИмя: " << name;
        cout << "\nНомер: " << number;
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
        cout << "Введите компенсацию: ";
        cin >> compensation;
        char p;
        cout << "Введите период оплаты (h - почасовая, w - понедельная, m - помесячная): ";
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
            cout << "Неверный выбор. Установлен период оплаты по умолчанию - почасовой.\n";
            period = Hourly;
        }
    }

    void putdata() const {
        employee::putdata();
        cout << "\nКомпенсация: " << compensation;
        cout << "\nПериод оплаты: ";
        if (period == Hourly) {
            cout << "Почасовая";
        }
        else if (period == Weekly) {
            cout << "Понедельная";
        }
        else if (period == Monthly) {
            cout << "Помесячная";
        }
    }
};

class laborer2 : public employee2 {  
private:
    string jobTitle;

public:
    void getdata() {
        employee2::getdata();
        cout << "Введите должность рабочего: ";
        cin >> jobTitle;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nДолжность рабочего: " << jobTitle;
    }
};

class manager2 : public employee2 { 
private:
    string department;

public:
    void getdata() {
        employee2::getdata();
        cout << "Введите департамент менеджера: ";
        cin >> department;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nДепартамент менеджера: " << department;
    }
};

class scientist2 : public employee2 {  
private:
    string researchField;

public:
    void getdata() {
        employee2::getdata();
        cout << "Введите область исследований ученого: ";
        cin >> researchField;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nОбласть исследований: " << researchField;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    laborer2 laborer;
    manager2 manager;
    scientist2 scientist;

    cout << "\nДанные рабочего:\n";
    laborer.getdata();
    laborer.putdata();

    cout << "\n\nДанные менеджера:\n";
    manager.getdata();
    manager.putdata();

    cout << "\n\nДанные ученого:\n";
    scientist.getdata();
    scientist.putdata();

    cout << endl;
    return 0;
}
