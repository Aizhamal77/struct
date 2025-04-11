#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    const int NUMARRAYS = 10;
    const int MAXSIZE = 10;

    int* ap[NUMARRAYS];

    for (int j = 0; j < NUMARRAYS; ++j) {
        ap[j] = new int[MAXSIZE];

        for (int k = 0; k < MAXSIZE; ++k) {
            ap[j][k] = j * MAXSIZE + k;
        }
    }

    // ������� ��� ������, ����� ���������, ��� ������� ��������� ���������
    cout << "����������� ������:" << endl;
    for (int j = 0; j < NUMARRAYS; ++j) {
        cout << "������ " << j << ": ";
        for (int k = 0; k < MAXSIZE; ++k) {
            cout << ap[j][k] << " ";
        }
        cout << endl;
    }

    // ����������� ������, ���������� ��� ������� �������
    for (int j = 0; j < NUMARRAYS; ++j) {
        delete[] ap[j];
    }

    return 0;
}
