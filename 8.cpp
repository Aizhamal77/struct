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
            cout << "������ ����.\n";
            return;
        }
        cout << "���������� ������: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "�� ������� ������� ���� ��� ������.\n";
            return;
        }

        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }

        file.close();
        cout << "������ ������� � ����: " << filename << endl;
    }

 
    void loadFromFile(const string& filename) {
        delite(); 

        ifstream file(filename);
        if (!file) {
            cerr << "�� ������� ������� ���� ��� ������.\n";
            return;
        }

        int value;
        while (file >> value) {
            add(value);
        }

        file.close();
        cout << "������ �������� �� �����: " << filename << endl;
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
        cout << "\n�������� ��������:\n"
            << "1. �������� ������� � ������\n"
            << "2. �������� ��� �������� ������\n"
            << "3. ��������� ������ � ����\n"
            << "4. ��������� ������ �� �����\n"
            << "0. �����\n"
            << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "������� ����� �����: ";
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
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "�������� �����. ��������� �������.\n";
        }
    } while (choice != 0);

    return 0;
}
