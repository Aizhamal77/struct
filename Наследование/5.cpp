#include <iostream>
#include <string>
using namespace std;

class employee {  
protected:
    string name;
    string number;

public:
    void getdata() {
        cout << "\nÂâåäèòå èìÿ: ";
        cin >> name;
        cout << "Ââåäèòå íîìåð ñîòðóäíèêà: ";
        cin >> number;
    }

    void putdata() const {
        cout << "\nÈìÿ: " << name;
        cout << "\nÍîìåð: " << number;
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
        cout << "Ââåäèòå êîìïåíñàöèþ: ";
        cin >> compensation;
        char p;
        cout << "Ââåäèòå ïåðèîä îïëàòû (h - ïî÷àñîâàÿ, w - ïîíåäåëüíàÿ, m - ïîìåñÿ÷íàÿ): ";
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
            cout << "Íåâåðíûé âûáîð. Óñòàíîâëåí ïåðèîä îïëàòû ïî óìîë÷àíèþ - ïî÷àñîâîé.\n";
            period = Hourly;
        }
    }

    void putdata() const {
        employee::putdata();
        cout << "\nÊîìïåíñàöèÿ: " << compensation;
        cout << "\nÏåðèîä îïëàòû: ";
        if (period == Hourly) {
            cout << "Ïî÷àñîâàÿ";
        }
        else if (period == Weekly) {
            cout << "Ïîíåäåëüíàÿ";
        }
        else if (period == Monthly) {
            cout << "Ïîìåñÿ÷íàÿ";
        }
    }
};

class laborer2 : public employee2 {  
private:
    string jobTitle;

public:
    void getdata() {
        employee2::getdata();
        cout << "Ââåäèòå äîëæíîñòü ðàáî÷åãî: ";
        cin >> jobTitle;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nÄîëæíîñòü ðàáî÷åãî: " << jobTitle;
    }
};

class manager2 : public employee2 { 
private:
    string department;

public:
    void getdata() {
        employee2::getdata();
        cout << "Ââåäèòå äåïàðòàìåíò ìåíåäæåðà: ";
        cin >> department;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nÄåïàðòàìåíò ìåíåäæåðà: " << department;
    }
};

class scientist2 : public employee2 {  
private:
    string researchField;

public:
    void getdata() {
        employee2::getdata();
        cout << "Ââåäèòå îáëàñòü èññëåäîâàíèé ó÷åíîãî: ";
        cin >> researchField;
    }

    void putdata() const {
        employee2::putdata();
        cout << "\nÎáëàñòü èññëåäîâàíèé: " << researchField;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    laborer2 laborer;
    manager2 manager;
    scientist2 scientist;

    cout << "\nÄàííûå ðàáî÷åãî:\n";
    laborer.getdata();
    laborer.putdata();

    cout << "\n\nÄàííûå ìåíåäæåðà:\n";
    manager.getdata();
    manager.putdata();

    cout << "\n\nÄàííûå ó÷åíîãî:\n";
    scientist.getdata();
    scientist.putdata();

    cout << endl;
    return 0;
}
