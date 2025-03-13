#include <iostream> 
#include <string> 
using namespace std;

class employee{
private:
    string name;
    long number;
public:
    void getdata() {
        cout << "\nÂâåäèòå èìÿ:"; cin >> name;
        cout << "Ââåäèòå íîìåð:"; cin >> number;
    }
    void putdata(){
        cout << "\n Èìÿ:" << name;
        cout << "\n Íîìåð:" << number;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");

    employee emparr[100]; 
    int n = 0;              
    char ch;               
    do {                   
        cout << "\nÂâåäèòå äàííûå î ðàáîòíèêå ñ íîìåðîì " << n + 1;
        emparr[n++].getdata();
        cout << "Ïðîäîëæèòü (y/n)?"; cin >> ch;
    } while (ch != 'n');
    for (int j = 0; j < n; j++){
        cout << "\nÍîìåð ðàáîòíèêà " << j + 1;
        emparr[j].putdata();
    }
    cout << endl;
    return 0;
}
