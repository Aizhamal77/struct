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
            cout << "Список пуст.\n";
            return;
        }
        cout << "Содержимое списка: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Не удалось открыть файл для записи.\n";
            return;
        }

        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }

        file.close();
        cout << "Список сохранён в файл: " << filename << endl;
    }

 
    void loadFromFile(const string& filename) {
        delite(); 

        ifstream file(filename);
        if (!file) {
            cerr << "Не удалось открыть файл для чтения.\n";
            return;
        }

        int value;
        while (file >> value) {
            add(value);
        }

        file.close();
        cout << "Список загружен из файла: " << filename << endl;
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
        cout << "\nВыберите действие:\n"
            << "1. Добавить элемент в список\n"
            << "2. Показать все элементы списка\n"
            << "3. Сохранить список в файл\n"
            << "4. Загрузить список из файла\n"
            << "0. Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Введите целое число: ";
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
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Повторите попытку.\n";
        }
    } while (choice != 0);

    return 0;
}
