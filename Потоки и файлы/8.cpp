#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkList {
private:
    Node* head;

public:
    LinkList() : head(nullptr) {}

    void add(int d) {
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        if (!current) {
            cout << "Ñïèñîê ïóñò.\n";
            return;
        }
        cout << "Ñîäåðæèìîå ñïèñêà: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Íå óäàëîñü îòêðûòü ôàéë äëÿ çàïèñè.\n";
            return;
        }

        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }

        file.close();
        cout << "Ñïèñîê ñîõðàí¸í â ôàéë: " << filename << endl;
    }

 
    void loadFromFile(const string& filename) {
        delite(); 

        ifstream file(filename);
        if (!file) {
            cerr << "Íå óäàëîñü îòêðûòü ôàéë äëÿ ÷òåíèÿ.\n";
            return;
        }

        int value;
        while (file >> value) {
            add(value);
        }

        file.close();
        cout << "Ñïèñîê çàãðóæåí èç ôàéëà: " << filename << endl;
    }

    void delite() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    ~LinkList() {
        delite();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    LinkList list;
    int choice;

    do {
        cout << "\nÂûáåðèòå äåéñòâèå:\n"
            << "1. Äîáàâèòü ýëåìåíò â ñïèñîê\n"
            << "2. Ïîêàçàòü âñå ýëåìåíòû ñïèñêà\n"
            << "3. Ñîõðàíèòü ñïèñîê â ôàéë\n"
            << "4. Çàãðóçèòü ñïèñîê èç ôàéëà\n"
            << "0. Âûõîä\n"
            << "Âàø âûáîð: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Ââåäèòå öåëîå ÷èñëî: ";
            cin >> value;
            list.add(value);
            break;
        }
        case 2:
            list.display();
            break;
        case 3:
            list.saveFile("list.txt");
            break;
        case 4:
            list.loadFromFile("list.txt");
            break;
        case 0:
            cout << "Âûõîä èç ïðîãðàììû.\n";
            break;
        default:
            cout << "Íåâåðíûé âûáîð. Ïîâòîðèòå ïîïûòêó.\n";
        }
    } while (choice != 0);

    return 0;
}
