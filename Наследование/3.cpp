#include <iostream>
#include <string>
using namespace std;

class publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cout << "\nÂâåäèòå çàãîëîâîê: ";
        cin >> title;
        cout << "Ââåäèòå öåíó: ";
        cin >> price;
    }

    void putdata() const {
        cout << "\nÇàãîëîâîê: " << title;
        cout << "\nÖåíà: " << price;
    }
};

class sales {
private:
    enum { MONTHS = 3 };
    float salesArr[MONTHS];

public:
    void getdata() {
        cout << "Ââåäèòå îáúåì ïðîäàæ çà 3 ìåñÿöà:\n ";
        for (int j = 0; j < MONTHS; j++) {
            cout << " Ìåñÿö " << j + 1 << ": ";
            cin >> salesArr[j];
        }
    }

    void putdata() const {
        for (int j = 0; j < MONTHS; j++) {
            cout << "\nÏðîäàæè çà ìåñÿö " << j + 1 << ": " << salesArr[j];
        }
    }
};

class book : private publication, private sales {
private:
    int pages;

public:
    void getdata() {
        publication::getdata();
        cout << "Ââåäèòå ÷èñëî ñòðàíèö: ";
        cin >> pages;
        sales::getdata();
    }

    void putdata() const {
        publication::putdata();
        cout << "\nÑòðàíèö: " << pages;
        sales::putdata();
    }
};

class tape : private publication, private sales {
private:
    float time;

public:
    void getdata() {
        publication::getdata();
        cout << "Ââåäèòå âðåìÿ çâó÷àíèÿ: ";
        cin >> time;
        sales::getdata();
    }

    void putdata() const {
        publication::putdata();
        cout << "\nÂðåìÿ çâó÷àíèÿ: " << time;
        sales::putdata();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    book book1;
    tape tape1;

    book1.getdata();
    tape1.getdata();

    book1.putdata();
    tape1.putdata();

    cout << endl;

    return 0;
}
