#include <iostream>
#include <cmath>
using namespace std;

class fraction {
private:
    int chis, zznam;

    int gcd(int a, int b) {  // Íàõîæäåíèå ÍÎÄ
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void lowterms() {
        int divisor = gcd(abs(chis), abs(zznam));
        chis /= divisor;
        zznam /= divisor;
    }

public:
    fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Îøèáêà: äåëåíèå íà 0!" << endl;
            exit(1);
        }
        chis = num;
        zznam = denom;
        lowterms();  // Ïðèâîäèì ê íåñîêðàòèìîìó âèäó ñðàçó ïðè èíèöèàëèçàöèè
    }

    void setFraction() {
        cout << "Ââåäèòå ÷èñëèòåëü: ";
        cin >> chis;
        cout << "Ââåäèòå çíàìåíàòåëü: ";
        cin >> zznam;
        if (zznam == 0) {
            cout << "Îøèáêà: äåëåíèå íà 0!" << endl;
            exit(1);
        }
        lowterms();
    }

    void display() const {
        cout << chis << "/" << zznam;
    }

    fraction operator + (const fraction& f) const {
        int num = chis * f.zznam + f.chis * zznam;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator - (const fraction& f) const {
        int num = chis * f.zznam - f.chis * zznam;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator * (const fraction& f) const {
        int num = chis * f.chis;
        int denom = zznam * f.zznam;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    fraction operator / (const fraction& f) const {
        if (f.chis == 0) {
            cout << "Îøèáêà: äåëåíèå íà 0!" << endl;
            exit(1);
        }
        int num = chis * f.zznam;
        int denom = zznam * f.chis;
        fraction result(num, denom);
        result.lowterms();
        return result;
    }

    bool operator == (const fraction& f) const {
        return chis == f.chis && zznam == f.zznam;
    }

    bool operator != (const fraction& f) const {
        return !(*this == f);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    fraction f1, f2, result;
    int choice;

    f1.setFraction();
    f2.setFraction();

    do {
        cout << "\nÌåíþ êàëüêóëÿòîðà äðîáåé:" << endl;
        cout << "1. Ñëîæåíèå" << endl;
        cout << "2. Âû÷èòàíèå" << endl;
        cout << "3. Óìíîæåíèå" << endl;
        cout << "4. Äåëåíèå" << endl;
        cout << "5. Âûõîä" << endl;
        cout << "Ââåäèòå âàø âûáîð: ";
        cin >> choice;

        switch (choice) {
        case 1:
            result = f1 + f2;
            cout << "Ðåçóëüòàò ñëîæåíèÿ: ";
            result.display();
            cout << endl;
            break;
        case 2:
            result = f1 - f2;
            cout << "Ðåçóëüòàò âû÷èòàíèÿ: ";
            result.display();
            cout << endl;
            break;
        case 3:
            result = f1 * f2;
            cout << "Ðåçóëüòàò óìíîæåíèÿ: ";
            result.display();
            cout << endl;
            break;
        case 4:
            result = f1 / f2;
            cout << "Ðåçóëüòàò äåëåíèÿ: ";
            result.display();
            cout << endl;
            break;
        case 5:
            cout << "Âûõîä èç ïðîãðàììû..." << endl;
            break;
        default:
            cout << "Íåâåðíûé âûáîð, ïîïðîáóéòå ñíîâà." << endl;
        }

    } while (choice != 5);

    return 0;
}
