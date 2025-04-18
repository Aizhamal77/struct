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
        cout << "\nВведите заголовок: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "\nЗаголовок: " << title;
        cout << "\nЦена: " << price;
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
        cout << "Введите число страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\nСтраниц: " << pages;
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
        cout << "Введите время звучания (в минутах): ";
        cin >> time;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\nВремя звучания: " << time << " минут";
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
            cout << "\nВводить данные для книги или пленки (b/t)? ";
            cin >> choice;

            publication* pub = nullptr;
            if (choice == 'b' || choice == 'B') {
                pub = new book;
            }
            else if (choice == 't' || choice == 'T') {
                pub = new tape;
            }
            else {
                cout << "Неверный выбор. Попробуйте снова.\n";
                continue;
            }

            pub->getdata();
            pubList.push_back(pub);

            cout << "Добавить ещё одну публикацию? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void outputPublications() const {
        cout << "\n--- Список публикаций ---";
        for (const auto& pub : pubList) {
            pub->putdata();
            if (pub->isOversize()) {
                cout << "\nПревышение размера!";
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
