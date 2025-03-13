#include <iostream> 
#include <cstring>
using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    void reversit(char[]);  
    const int MAX = 80;         
    char str[MAX];            
    cout << "\nВведите строку:";
    cin.get(str, MAX);
    reversit(str);             
    cout << "Перевернутая строка:";
    cout << str << endl;
    return 0;
}


void reversit(char s[]){
    int len = strlen(s);       
    for (int j = 0; j < len / 2; j++){
        char temp = s[j];       
        s[j] = s[len - j - 1];    
        s[len - j - 1] = temp;
    }
}