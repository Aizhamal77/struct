#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    enum { SZ = 80 };
    char str[SZ];

public:
    String() {
        str[0] = '\0';
    }

    String(const char s[]) {
        strcpy_s(str, SZ, s);  
    }

    void display() const {
        cout << str;
    }

    operator char* () {
        return str;
    }
};

class Pstring : public String {
public:
    explicit Pstring(const char s[]); 
};

Pstring::Pstring(const char s[]) {
    if (strlen(s) > SZ - 1) {
        for (int j = 0; j < SZ - 1; j++) {
            str[j] = s[j];
        }
        str[SZ - 1] = '\0';
    }
    else {
        strcpy_s(str, SZ, s);  
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    Pstring s1("Это очень-очень длинная строка, которая, возможно, да, нет, точно, -- превысит размер, ограниченный SZ.");
    cout << "\ns1=";
    s1.display();

    Pstring s2("А это коротенькая строка.");
    cout << "\ns2=";
    s2.display();

    cout << endl;

    return 0;
}
