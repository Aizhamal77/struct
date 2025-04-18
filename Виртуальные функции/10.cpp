#include <iostream>
using namespace std;

class LinkList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;  

public:
    LinkList() : head(nullptr) {}

    ~LinkList() {
        delite();
    }

    LinkList(const LinkList& other) : head(nullptr) {
        copyFrom(other);
    }

    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this; 
        delite(); 
        copyFrom(other);  
        return *this;
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void show() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    void copyFrom(const LinkList& other) {
        Node* current = other.head;
        while (current) {
            add(current->data);  
            current = current->next;
        }
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
};

class ListActions {
public:
    void execute() {
        LinkList list1;
        list1.add(1);
        list1.add(2);
        list1.add(3);
        cout << "List 1: ";
        list1.show();

        LinkList list2 = list1;
        cout << "List 2 (copy of List 1): ";
        list2.show();

        LinkList list3;
        list3 = list1;
        cout << "List 3 (assigned from List 1): ";
        list3.show();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    ListActions actions;
    actions.execute();  
    return 0;
}
