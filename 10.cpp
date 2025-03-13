#include <iostream>
using namespace std;

class Angle {
private:
    int degrees;   
    float minutes;  
    char direction; 

public:
    Angle(int deg = 0, float min = 0.0, char dir = 'N') : degrees(deg), minutes(min), direction(dir) {}

    void input() {
        char slash; 
        cout << "������� �������: ";
        cin >> degrees;
        cout << "������� ������: ";
        cin >> minutes;
        cout << "������� ����������� (N, S, E, W): ";
        cin >> direction;

        if (minutes < 0 || minutes >= 60) {
            cout << "������! ������ ������ ���� � ��������� �� 0 �� 59." << endl;
            minutes = 0.0;
        }
    }

    void display() const {
        cout << degrees << "\xF8" << minutes << "'" << " " << direction;
    }
};


class Ship {
private:
    static int shipCount; 
    int shipNumber;    
    Angle latitude;    
    Angle longitude;   

public:

    Ship() {
        shipNumber = ++shipCount;  
    }

 
    void input() {
        cout << "\n������� #" << shipNumber << endl;
        cout << "������� ������ � ������: ";
        latitude.input();
        cout << "������� ������ � �������: ";
        longitude.input();
    }

    void display() const {
        cout << "������� #" << shipNumber << endl;
        cout << "������: ";
        latitude.display();
        cout << "\n�������: ";
        longitude.display();
        cout << endl;
    }
};

int Ship::shipCount = 0;

int main() {
    setlocale(LC_ALL, "Rus");
    Ship ship1, ship2, ship3;

    ship1.input();
    ship2.input();
    ship3.input();

    ship1.display();
    ship2.display();
    ship3.display();

    return 0;
}
