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
        cout << "\n������� ���������: ";
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "\n���������: " << title;
        cout << "\n����: " << price;
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
        cout << "������� ����� �������: ";
        cin >> pages;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\n�������: " << pages;
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
        cout << "������� ����� �������� (� �������): ";
        cin >> time;
    }

    void putdata() const override {
        publication::putdata();
        cout << "\n����� ��������: " << time << " �����";
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
            cout << "\n������� ������ ��� ����� ��� ������ (b/t)? ";
            cin >> choice;

            publication* pub = nullptr;
            if (choice == 'b' || choice == 'B') {
                pub = new book;
            }
            else if (choice == 't' || choice == 'T') {
                pub = new tape;
            }
            else {
                cout << "�������� �����. ���������� �����.\n";
                continue;
            }

            pub->getdata();
            pubList.push_back(pub);

            cout << "�������� ��� ���� ����������? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void outputPublications() const {
        cout << "\n--- ������ ���������� ---";
        for (const auto& pub : pubList) {
            pub->putdata();
            if (pub->isOversize()) {
                cout << "\n���������� �������!";
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
