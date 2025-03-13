#include <iostream>
using namespace std;

class Object {
private:
    int serialNumber;  
    static int objectCount; 

public:
    Object() {
        serialNumber = ++objectCount; 
    }

    void displaySerialNumber() const {
        cout << "Мой порядковый номер: " << serialNumber << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};


int Object::objectCount = 0;

int main() {
    setlocale(LC_ALL, "Rus");
    Object obj1;
    Object obj2;
    Object obj3;

    obj1.displaySerialNumber();
    obj2.displaySerialNumber();
    obj3.displaySerialNumber();

    return 0;
}
