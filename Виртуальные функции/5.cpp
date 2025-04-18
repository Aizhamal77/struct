#include <iostream>
#include <string>
#include <vector>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cin.ignore();
        cout << "\nÂâåäèòå çàãîëîâîê: ";
        getline(cin, title);
        cout << "Ââåäèòå öåíó: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "\nÇàãîëîâîê: " << title;
        cout << "\nÖåíà: " << price;
    }

    virtual bool isOversize() const {
        return false; 
    }

    virtual ~publication() {}
};

class book : public publication {
private:
    int pages;

public:
    void getdata() override {
        publication::getdata();
        cout << "Ââåäèòå ÷èñëî ñòðàíèö: ";
        cin >> pages;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\nÑòðàíèö: " << pages;
    }

    bool isOversize() const override {
        return pages > 800; 
    }
};

class tape : public publication {
private:
    float time;

public:
    void getdata() override {
        publication::getdata();
        cout << "Ââåäèòå âðåìÿ çâó÷àíèÿ (â ìèíóòàõ): ";
        cin >> time;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\nÂðåìÿ çâó÷àíèÿ: " << time << " ìèíóò";
    }

    bool isOversize() const override {
        return time > 90.0f; 
    }
};

class use {
private:
    vector<publication*> pubList;

public:
    void show() {
        inputPublications();
        outputPublications();
        delPublications();
    }

private:
    void inputPublications() {
        char choice;
        do {
            cout << "\nÂâîäèòü äàííûå äëÿ êíèãè èëè ïëåíêè (b/t)? ";
            cin >> choice;

            publication* pub = nullptr;
            if (choice == 'b' || choice == 'B') {
                pub = new book;
            }
            else if (choice == 't' || choice == 'T') {
                pub = new tape;
            }
            else {
                cout << "Íåâåðíûé âûáîð. Ïîïðîáóéòå ñíîâà.\n";
                continue;
            }

            pub->getdata();
            pubList.push_back(pub);

            cout << "Äîáàâèòü åù¸ îäíó ïóáëèêàöèþ? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void outputPublications() const {
        cout << "\n--- Ñïèñîê ïóáëèêàöèé ---";
        for (const auto& pub : pubList) {
            pub->putdata();
            if (pub->isOversize()) {
                cout << "\nÏðåâûøåíèå ðàçìåðà!";
            }
            cout << "\n-------------------------";
        }
    }

    void delPublications() {
        for (auto& pub : pubList) {
            delete pub;
        }
        pubList.clear();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    use app;
    app.show();
    return 0;
}
