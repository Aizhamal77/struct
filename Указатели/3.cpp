#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

const int DAYS = 7;

void bsort(const char** arr, int n);
void order(const char** pp1, const char** pp2);

int main() {
    setlocale(LC_ALL, "Rus");

    const char* arrptrs[DAYS] = {
        "Âîñêðåñåíüå",
        "Ïîíåäåëüíèê",
        "Âòîðíèê",
        "Ñðåäà",
        "×åòâåðã",
        "Ïÿòíèöà",
        "Ñóááîòà"
    };

    cout << "\nÍåóïîðÿäî÷åííûå:\n";
    for (int i = 0; i < DAYS; i++) {
        cout << arrptrs[i] << endl;
    }

    bsort(arrptrs, DAYS);

    cout << "\nÓïîðÿäî÷åííûå:\n";
    for (int i = 0; i < DAYS; i++) {
        cout << arrptrs[i] << endl;
    }

    return 0;
}

void bsort(const char** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            order(&arr[i], &arr[j]);
        }
    }
}

void order(const char** pp1, const char** pp2) {
    if (strcmp(*pp1, *pp2) > 0) {
        const char* temp = *pp1;
        *pp1 = *pp2;
        *pp2 = temp;
    }
}
