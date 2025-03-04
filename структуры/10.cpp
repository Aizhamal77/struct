#include <iostream>
using namespace std;


struct sterling {
    int pounds; 
    int shillings; 
    int pence;     
};

int main() {
    setlocale(LC_ALL, "Rus");
    double decimalPounds;

    cout << "Ââåäèòå ñóììó â ôóíòàõ (äåñÿòè÷íàÿ ñèñòåìà): ";
    cin >> decimalPounds;


    sterling money;
    money.pounds = int(decimalPounds); 
    money.shillings = int((decimalPounds - money.pounds) * 20); 
    money.pence = int(((decimalPounds - money.pounds) * 20 - money.shillings) * 12); 

   
    cout << "Ñóììà â ñòàðîé ñèñòåìå: "
        << money.pounds << " ôóíòîâ, "
        << money.shillings << " øèëëèíãîâ, "
        << money.pence << " ïåíñîâ." << endl;

    return 0;
}
