#include <iostream>
#include <string>
using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cout << "\nÂâåäèòå çàãîëîâîê: ";
        getline(cin, title);  
        cout << "Ââåäèòå öåíó: ";
        cin >> price;
        cin.ignore(); 
    }

    void putdata() const {
        cout << "\nÇàãîëîâîê: " << title;
        cout << "\nÖåíà: " << price;
    }
};

class Book : private Publication {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "Ââåäèòå ÷èñëî ñòðàíèö: ";
        cin >> pages;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\nÑòðàíèö: " << pages;
    }
};

class Tape : private Publication {
private:
    float time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Ââåäèòå âðåìÿ çâó÷àíèÿ: ";
        cin >> time;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\nÂðåìÿ çâó÷àíèÿ: " << time;
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
