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

// Äîáàâëåíèå êëàññà disk
class disk : private publication, private sales {
private:
    enum disk_type { CD, DVD };
    disk_type type;

public:
    void getdata() {
        publication::getdata();
        cout << "Ââåäèòå òèï äèñêà (ñ - CD, d - DVD): ";
        char choice;
        cin >> choice;
        if (choice == 'c' || choice == 'C') {
            type = CD;
        }
        else if (choice == 'd' || choice == 'D') {
            type = DVD;
        }
        else {
            cout << "Íåâåðíûé âûáîð. Óñòàíîâëåí òèï CD ïî óìîë÷àíèþ.\n";
            type = CD;
        }
        sales::getdata();
    }

    void putdata() const {
        publication::putdata();
        cout << "\nÒèï äèñêà: " << (type == CD ? "CD" : "DVD");
        sales::putdata();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    book book1;
    tape tape1;
    disk disk1;

    book1.getdata();
    tape1.getdata();
    disk1.getdata();

    book1.putdata();
    tape1.putdata();
    disk1.putdata();

    cout << endl;

    return 0;
}
