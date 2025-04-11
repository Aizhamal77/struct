#include <iostream>
using namespace std;

struct link {
    int data;     
    link* next;    
};

class linklist {
private:
    link* first; 

public:
    linklist() { first = nullptr; }  
    ~linklist();  

    void additem(int d);  
    void display();       
};

// Добавление элемента в конец списка
void linklist::additem(int d) {
    link* newLink = new link;   
    newLink->data = d;         
    newLink->next = nullptr;    

    if (first == nullptr) {   
        first = newLink;    
    }
    else {
        link* current = first;  
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = newLink;     
    }
}

// Вывод всех элементов списка
void linklist::display() {
    link* current = first;  
    while (current != nullptr) {
        cout << current->data << endl; 
        current = current->next;       
    }
}

// Деструктор для удаления всех элементов
linklist::~linklist() {
    link* current = first; 
    while (current != nullptr) {
        link* temp = current; 
        current = current->next;  
        delete temp;  
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    linklist li; 
    li.additem(25);  
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();  

    return 0;
}
