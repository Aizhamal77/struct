#include <iostream>
#include <cstring>
#include <process.h>
using namespace std;

class String {
private:
    enum { SZ = 80 };
    char str[SZ];

public:
    String() {
        strcpy_s(str, SZ, "");
    }

    String(const char s[]) {
        strcpy_s(str, SZ, s);
    }

    void display() const {
        cout << str;
    }

    String operator +=(const String& ss) {
        if (strlen(str) + strlen(ss.str) >= SZ) {
            cout << "\nÏåðåïîëíåíèå ñòðîêè";
            exit(1);
        }
        strcat_s(str, SZ, ss.str);
        return String(str);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    String s1("Ñ Íîâûì Ãîäîì!");
    String s2("Óðà, òîâàðèùè!");
    String s3;

    s3 = s1 += s2;

    cout << "\ns1=";
    s1.display();
    cout << "\ns2=";
    s2.display();
    cout << "\ns3=";
    s3.display();
    cout << endl;

    return 0;
}
