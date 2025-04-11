#include <iostream>
#include <cstring>  
#include <cctype>   
using namespace std;

class String {
private:
    char* str; 

public:
   
    String(const char* s) {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);       
    }

    ~String() {
        delete[] str; 
        str = nullptr;
    }

    void show() const {
        cout << str;
    }

    void upit() {
        char* ptr = str;
        while (*ptr) {
            *ptr = toupper(*ptr); 
            ptr++;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    String s1 = "My home is very, very beeg";

    cout << "\ns1 = ";
    s1.show();

    s1.upit(); 

    cout << "\ns1 = ";
    s1.show();

    cout << endl;
    return 0;
}
