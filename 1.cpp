#include <iostream>
#include <string>
using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cout << "\nВведите заголовок: ";
        getline(cin, title);  
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore(); 
    }

    void putdata() const {
        cout << "\nЗаголовок: " << title;
        cout << "\nЦена: " << price;
    }
};

class Book : private Publication {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите число страниц: ";
        cin >> pages;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\nСтраниц: " << pages;
    }
};

class Tape : private Publication {
private:
    float time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите время звучания: ";
        cin >> time;
        cin.ignore(); 
    }

    void putdata() const {
        Publication::putdata();
        cout << "\nВремя звучания: " << time;
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
