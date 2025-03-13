#include <iostream>
using namespace std;

class Angle {
private:
    int degrees; 
    float minutes; 
    char direction; 

public:
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}

    void input() {
        cout << "������� �������: ";
        cin >> degrees;
        cout << "������� ������: ";
        cin >> minutes;
        cout << "������� ����������� (N, S, E, W): ";
        cin >> direction;
    }

    void display() const {
        cout << degrees << "\xF8" << minutes << "'" << " " << direction << endl;
    }

    int getDegrees() const {
        return degrees;
    }

    float getMinutes() const {
        return minutes;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Angle coordinate(149, 34.8, 'E');
    cout << "���������� ����� ������ �� �. �����: ";
    coordinate.display();

    Angle userCoordinate(0, 0.0, 'N'); 

    while (true) {
        cout << "\n������� ���������� (��� ������� 0 ��� ������):" << endl;
        userCoordinate.input();
        if (userCoordinate.getDegrees() == 0 && userCoordinate.getMinutes() == 0.0) {
            break;
        }
        cout << "��������� ����������: ";
        userCoordinate.display();
    }

    return 0;
}
