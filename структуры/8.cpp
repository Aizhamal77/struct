#include <iostream>
using namespace std;

struct fraction {
    int numerator;  
    int denominator; 
};


fraction addFractions(fraction frac1, fraction frac2) {
    fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;

   
    int gcd = 1;
    for (int i = 1; i <= result.numerator && i <= result.denominator; i++) {
        if (result.numerator % i == 0 && result.denominator % i == 0) {
            gcd = i;
        }
    }

    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}


void printFraction(fraction frac) {
    cout << frac.numerator << "/" << frac.denominator << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    fraction frac1, frac2;


    cout << "Ââåäèòå ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: ";
    cin >> frac1.numerator >> frac1.denominator;
    cout << "Ââåäèòå ÷èñëèòåëü è çíàìåíàòåëü âòîðîé äðîáè: ";
    cin >> frac2.numerator >> frac2.denominator;


    if (frac1.denominator == 0 || frac2.denominator == 0) {
        cout << "Çíàìåíàòåëü íå ìîæåò áûòü ðàâåí íóëþ!" << endl;
        return 1;
    }


    fraction result = addFractions(frac1, frac2);


    cout << "Ðåçóëüòàò ñëîæåíèÿ äðîáåé: ";
    printFraction(result);

    return 0;
}
