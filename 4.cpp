#include <iostream>
using namespace std;

struct Link {
    int data;
    Link* next;
};

class LinkList {
private:
    Link* first;

public:
    LinkList() : first(nullptr) {}

    ~LinkList() {
        Link* current = first;
        while (current != nullptr) {
            Link* temp = current;
            current = current->next;
            cout << "�������� ��������: " << temp->data << endl;
            delete temp;
        }
        cout << "��� �������� ������ ���� �������." << endl;
    }

    void addItem(int data) {
        Link* newLink = new Link;
        newLink->data = data;
        newLink->next = first;
        first = newLink;
    }

    void display() const {
        Link* current = first;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    LinkList list;

    list.addItem(25);
    list.addItem(36);
    list.addItem(49);
    list.addItem(64);

    cout << "���������� ������:" << endl;
    list.display();

    return 0;
}
