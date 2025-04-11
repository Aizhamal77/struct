#include <iostream>
#include <iomanip>  
using namespace std;

class Arr {
private:
    float arr[100];
    int count;

public:
    Arr() : count(0) {}

    void addNum(float num) {
        if (count < 100) {
            *(arr + count) = num;
            count++;
        }
        else {
            cout << "�������� ����� ����� (100)." << endl;
        }
    }

    void input() {
        int choice = 1;
        float num;

        while (choice != 0) {
            cout << "������� �����: ";
            cin >> num;
            addNum(num);

            cout << "��� ����������� ������� 1, ����� 0: ";
            cin >> choice;
        }
    }

    float sred() const {
        if (count == 0) return 0.0f;

        float total = 0.0f;
        for (int i = 0; i < count; ++i) {
            total += *(arr + i);
        }
        return total / count;
    }

    void output() const {
        if (count > 0) {
            cout << fixed << setprecision(2); // ���������� �� 2 ������
            cout << "������� ��������: " << sred() << endl;
        }
        else {
            cout << "����� �� ���� �������." << endl;
        }
    }

    void show() {
        input();
        output();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Arr num;
    num.show();
    return 0;
}
