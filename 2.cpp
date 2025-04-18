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
};

class Publisher {
private:
    vector<publication*> pubList;

public:
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

        } while ((choice == 'y' || choice == 'Y'));
    }

    void outputPublications() const {
        cout << "\n--- ������ ���������� ---";
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
