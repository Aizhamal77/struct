#include <iostream>
using namespace std;

int maxint(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "������� ������� " << i + 1 << ": ";
        cin >> arr[i];
    }

    int maxIndex = maxint(arr, n);

    cout << "���������� �����: " << arr[maxIndex] << endl;
    cout << "������ ����������� �����: " << maxIndex << endl;

    delete[] arr;
    return 0;
}
