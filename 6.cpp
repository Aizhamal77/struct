#include <iostream>
using namespace std;

class String {
private:
    char* str; 

public:
    String(const char* s) {
        int length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i <= length; i++) {
            str[i] = s[i];
        }
    }

    ~String() {
        delete[] str;
    }

    int compstr(const String& other) const {
        const char* s1 = str;
        const char* s2 = other.str;

        while (*s1 != '\0' && *s2 != '\0') {
            if (*s1 < *s2) {
                return -1; 
            }
            else if (*s1 > *s2) {
                return 1;  
            }
            s1++;
            s2++;
        }

        if (*s1 == '\0' && *s2 == '\0') {
            return 0;  
        }
        else if (*s1 == '\0') {
            return -1;
        }
        else {
            return 1;  
        }
    }

   
    void input() {
        cout << "Введите строку: ";
        char buffer[100]; 
        cin.getline(buffer, 100);

        delete[] str;

        int length = 0;
        while (buffer[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i <= length; i++) {
            str[i] = buffer[i];
        }
    }

    void show() const {
        cout << str << endl;
    }

    void proverka() const {
        String testStr1("Hello");
        String testStr2("World");
        String testStr3("Hello");

        cout << "compstr(testStr1, testStr2) = " << testStr1.compstr(testStr2) << endl; 
        cout << "compstr(testStr2, testStr3) = " << testStr2.compstr(testStr3) << endl; 
        cout << "compstr(testStr1, testStr3) = " << testStr1.compstr(testStr3) << endl; 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    String str1("Привет");
    str1.show(); 

    str1.input();  
    str1.show(); 

    str1.proverka();   

    return 0;
}
