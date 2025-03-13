#include <iostream>
#include <cmath>
using namespace std;

class fraction {
private:
    int chis, zznam;

    int gcd(int a, int b) {  // ���������� ���
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
            cout << "������: ������� �� 0!" << endl;
            exit(1);
        }
        chis = num;
        zznam = denom;
        lowterms();  // �������� � ������������� ���� ����� ��� �������������
    }

    void setFraction() {
        cout << "������� ���������: ";
        cin >> chis;
        cout << "������� �����������: ";
        cin >> zznam;
        if (zznam == 0) {
            cout << "������: ������� �� 0!" << endl;
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
            cout << "������: ������� �� 0!" << endl;
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
        cout << "\n���� ������������ ������:" << endl;
        cout << "1. ��������" << endl;
        cout << "2. ���������" << endl;
        cout << "3. ���������" << endl;
        cout << "4. �������" << endl;
        cout << "5. �����" << endl;
        cout << "������� ��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            result = f1 + f2;
            cout << "��������� ��������: ";
            result.display();
            cout << endl;
            break;
        case 2:
            result = f1 - f2;
            cout << "��������� ���������: ";
            result.display();
            cout << endl;
            break;
        case 3:
            result = f1 * f2;
            cout << "��������� ���������: ";
            result.display();
            cout << endl;
            break;
        case 4:
            result = f1 / f2;
            cout << "��������� �������: ";
            result.display();
            cout << endl;
            break;
        case 5:
            cout << "����� �� ���������..." << endl;
            break;
        default:
            cout << "�������� �����, ���������� �����." << endl;
        }

    } while (choice != 5);

    return 0;
}
