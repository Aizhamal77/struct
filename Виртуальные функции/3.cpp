#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0f) {}

    Distance(float fltfeet) {
        feet = static_cast<int>(fltfeet);
        inches = (fltfeet - feet) * 12.0f;
    }

    Distance(int ft, float in) : feet(ft), inches(in) {}

    void input() {
        cout << "Ââåäèòå ôóòû: ";
        cin >> feet;
        cout << "Ââåäèòå äþéìû: ";
        cin >> inches;
    }

    void output() const {
        cout << feet << "\'-" << inches << '\"';
    }

    friend Distance operator*(Distance, Distance);
    friend Distance operator*(float, Distance);
};

Distance operator*(Distance d1, Distance d2) {
    float fltfeet1 = d1.feet + d1.inches / 12.0f;
    float fltfeet2 = d2.feet + d2.inches / 12.0f;
    return Distance(fltfeet1 * fltfeet2);
}

Distance operator*(float val, Distance d) {
    float fltfeet = d.feet + d.inches / 12.0f;
    return Distance(val * fltfeet);
}

class UseDistance {
private:
    Distance dist1, dist2, dist3;

public:
    void show() {
        input();
        calculate();
        output();
    }

private:
    void input() {
        cout << "Ââåäèòå ïåðâîå ðàññòîÿíèå:\n";
        dist1.input();

        cout << "Ââåäèòå âòîðîå ðàññòîÿíèå:\n";
        dist2.input();
    }

    void calculate() {
        dist3 = dist1 * dist2;
        dist3 = 10.0f * dist3;
    }

    void output() const {
        cout << "\ndist1 = ";
        dist1.output();

        cout << "\ndist2 = ";
        dist2.output();

        cout << "\ndist3 = ";
        dist3.output();

        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    UseDistance app;
    app.show();
    return 0;
}
