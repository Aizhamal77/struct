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
        cout << "Ââåäèòå äàòó â ôîðìàòå MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << "Äàòà: " << month << "/" << day << "/" << year << endl;
    }
};

class Publication {
private:
    string title;  
    float price; 

public:
    void getdata() {
        cout << "\nÂâåäèòå çàãîëîâîê: ";
        cin.ignore();  
        getline(cin, title); 
        cout << "Ââåäèòå öåíó: ";
        cin >> price;  
    }

    void putdata() const {
        cout << "\nÇàãîëîâîê: " << title;
        cout << "\nÖåíà: " << price;
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
        cout << "Ââåäèòå ÷èñëî ñòðàíèö: ";
        cin >> pages;
    }

    void putdata() const {
        Publication2::putdata(); 
        cout << "\nÑòðàíèö: " << pages;
    }
};

class Tape : public Publication2 {
private:
    float time;  

public:
    void getdata() {
        Publication2::getdata();  
        cout << "Ââåäèòå âðåìÿ çâó÷àíèÿ (â ìèíóòàõ): ";
        cin >> time;  
    }

    void putdata() const {
        Publication2::putdata();  
        cout << "\nÂðåìÿ çâó÷àíèÿ: " << time << " ìèíóò";
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Book book1;
    Tape tape1;

    cout << "Ââåäèòå äàííûå äëÿ êíèãè:\n";
    book1.getdata();

    cout << "\nÂâåäèòå äàííûå äëÿ àóäèîêàññåòû:\n";
    tape1.getdata();

    cout << "\nÄàííûå î êíèãå:\n";
    book1.putdata();

    cout << "\nÄàííûå îá àóäèîêàññåòå:\n";
    tape1.putdata();

    return 0;
}
