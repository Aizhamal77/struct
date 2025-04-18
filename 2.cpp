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
};

class Publisher {
private:
    vector<publication*> pubList;

public:
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

        } while ((choice == 'y' || choice == 'Y'));
    }

    void outputPublications() const {
        cout << "\n--- Список публикаций ---";
        for (const auto& pub : pubList) {
            pub->putdata(); 
            cout << "\n-------------------------";
        }
    }

    void deletePublications() {
        for (auto& pub : pubList) {
            delete pub; 
        }
        pubList.clear();  
    }

    void show() {
        inputPublications();
        outputPublications();
        deletePublications();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Publisher publisher;  
    publisher.show();  
    return 0;
}
