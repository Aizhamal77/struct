#include <iostream>
using namespace std;


struct sterling {
    int pounds;  
    int shillings;  
    int pence; 
};

sterling getSterling() {
    sterling amount;
    cout << "Ââåäèòå êîëè÷åñòâî ôóíòîâ: ";
    cin >> amount.pounds;
    cout << "Ââåäèòå êîëè÷åñòâî øèëëèíãîâ: ";
    cin >> amount.shillings;
    cout << "Ââåäèòå êîëè÷åñòâî ïåíñîâ: ";
    cin >> amount.pence;
    return amount;
}


sterling addSterling(const sterling& s1, const sterling& s2) {
    sterling result;
    result.pence = s1.pence + s2.pence;
    result.shillings = s1.shillings + s2.shillings + result.pence / 12;  
    result.pounds = s1.pounds + s2.pounds + result.shillings / 20; 

    result.pence = result.pence % 12;
    result.shillings = result.shillings % 20;

    return result;
}


void printSterling(const sterling& amount) {
    cout << amount.pounds << " ôóíòîâ, " << amount.shillings << " øèëëèíãîâ, " << amount.pence << " ïåíñîâ." << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Ââåäèòå ïåðâóþ äåíåæíóþ ñóììó:" << endl;
    sterling s1 = getSterling();

    cout << "Ââåäèòå âòîðóþ äåíåæíóþ ñóììó:" << endl;
    sterling s2 = getSterling();

    sterling result = addSterling(s1, s2);

    cout << "Ðåçóëüòàò ñëîæåíèÿ: ";
    printSterling(result);

    return 0;
}
