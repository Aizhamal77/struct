#include <iostream>
using namespace std;

class Fraction {
private:
    int chis;   
    int znam; 

public:
   
    Fraction() : chis(0), znam(1) {}

    void input() {
        char slash;  
        cout << "Ââåäèòå äðîáü (ôîðìàò: ÷èñëèòåëü/çíàìåíàòåëü): ";
        cin >> chis >> slash >> znam;

    
        if (znam == 0) {
            cout << "Îøèáêà! Çíàìåíàòåëü íå ìîæåò áûòü ðàâåí íóëþ." << endl;
            znam = 1; 
        }
    }

  
    void display() const {
        cout << chis << "/" << znam;
    }

  
    Fraction add(const Fraction& other) const {
       
        int newchis = chis * other.znam + znam * other.chis;
        int newznam = znam * other.znam;
        return Fraction(newchis, newznam);
    }

private:
   
    Fraction(int num, int den) : chis(num), znam(den) {}
};

int main() {
    setlocale(LC_ALL, "Rus");

    char continueChoice;

    do {
        Fraction fraction1, fraction2;

        fraction1.input();
        fraction2.input();

        Fraction result = fraction1.add(fraction2);

        cout << "Ðåçóëüòàò ñëîæåíèÿ: ";
        result.display();
        cout << endl;

        cout << "Õîòèòå ïðîäîëæèòü? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
