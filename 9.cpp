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
        cout << "Введите дату в формате MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << "Дата: " << month << "/" << day << "/" << year << endl;
    }
};

class Publication {
private:
    string title;  
    float price; 

public:
    void getdata() {
        cout << "\nВведите заголовок: ";
        cin.ignore();  
        getline(cin, title); 
        cout << "Введите цену: ";
        cin >> price;  
    }

    void putdata() const {
        cout << "\nЗаголовок: " << title;
        cout << "\nЦена: " << price;
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
        cout << "Введите число страниц: ";
        cin >> pages;
    }

    void putdata() const {
        Publication2::putdata(); 
        cout << "\nСтраниц: " << pages;
    }
};

class Tape : public Publication2 {
private:
    float time;  

public:
    void getdata() {
        Publication2::getdata();  
        cout << "Введите время звучания (в минутах): ";
        cin >> time;  
    }

    void putdata() const {
        Publication2::putdata();  
        cout << "\nВремя звучания: " << time << " минут";
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Book book1;
    Tape tape1;

    cout << "Введите данные для книги:\n";
    book1.getdata();

    cout << "\nВведите данные для аудиокассеты:\n";
    tape1.getdata();

    cout << "\nДанные о книге:\n";
    book1.putdata();

    cout << "\nДанные об аудиокассете:\n";
    tape1.putdata();

    return 0;
}
