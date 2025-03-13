#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 5;
    int arr[MAX];
    int head, tail;

public:
    Queue() : head(0), tail(0) {}

    void put(int value) {
        if ((tail + 1) % MAX == head) {
            cout << "Î÷åðåäü ïîëíà!" << endl;
        }
        else {
            arr[tail] = value;
            tail = (tail + 1) % MAX;
        }
    }

    int get() {
        if (head == tail) {
            cout << "Î÷åðåäü ïóñòà!" << endl;
            return -1;
        }
        else {
            int value = arr[head];
            head = (head + 1) % MAX;
            return value;
        }
    }

    void input() {
        int value;
        cout << "Ââåäèòå ÷èñëî äëÿ äîáàâëåíèÿ â î÷åðåäü: ";
        cin >> value;
        put(value);
    }

    void output() {
        int value = get();
        if (value != -1) {
            cout << "Èçâëå÷åííîå ÷èñëî: " << value << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Queue q;
    char choice;

    do {
        cout << "\n1. Äîáàâèòü ýëåìåíò â î÷åðåäü" << endl;
        cout << "2. Èçâëå÷ü ýëåìåíò èç î÷åðåäè" << endl;
        cout << "Âûáåðèòå äåéñòâèå (1 èëè 2): ";
        cin >> choice;

        if (choice == '1') {
            q.input();
        }
        else if (choice == '2') {
            q.output();
        }
        else {
            cout << "Íåâåðíûé âûáîð!" << endl;
        }

        cout << "Ïðîäîëæèòü (y/n)? ";
        cin >> choice;

    } while (choice == 'y');

    return 0;
}
