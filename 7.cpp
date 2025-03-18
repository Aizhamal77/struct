#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    void increase() {
        count++;
    }

    void decrease() {
        count--;
    }

    int getCount() const {
        return count;
    }

    void setCount(int value) {
        count = value;
    }

    Counter& operator++() { 
        ++count;
        return *this;
    }

    Counter& operator--() { 
        --count;
        return *this;
    }

    Counter operator++(int) { 
        Counter temp = *this;
        count++;
        return temp;
    }

    Counter operator--(int) {  
        Counter temp = *this;
        count--;
        return temp;
    }

    void input() {
        cout << "Введите значение счетчика: ";
        cin >> count;
    }

    void output() const {
        cout << "Значение счетчика: " << count << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Counter counter;

    counter.input();
    counter.output();

    ++counter;  
    counter.output();

    counter++; 
    counter.output();

    --counter;  
    counter.output();

    counter--; 
    counter.output();

    return 0;
}
