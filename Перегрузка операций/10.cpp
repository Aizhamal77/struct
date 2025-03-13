#include <iostream>
#include <cmath>  
using namespace std;

#define M_PI 3.14159265358979323846  // Îïðåäåëÿåì M_PI âðó÷íóþ

class Polar {
private:
    double r;
    double theta;

public:
    Polar() : r(0), theta(0) {}

    Polar(double radius, double angle) : r(radius), theta(angle) {}

    void display() const {
        cout << "r = " << r << ", theta = " << theta << " radians" << endl;
    }

    Polar operator + (const Polar& p) {
        double x1 = r * cos(theta);
        double y1 = r * sin(theta);
        double x2 = p.r * cos(p.theta);
        double y2 = p.r * sin(p.theta);

        double x_result = x1 + x2;
        double y_result = y1 + y2;

        double r_result = sqrt(x_result * x_result + y_result * y_result);
        double theta_result = atan2(y_result, x_result);

        return Polar(r_result, theta_result);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Polar p1(5, M_PI / 4); 
    Polar p2(3, M_PI / 3); 

    Polar p3 = p1 + p2;

    cout << "p1: ";
    p1.display();
    cout << "p2: ";
    p2.display();
    cout << "p3 (ðåçóëüòàò ñëîæåíèÿ p1 è p2): ";
    p3.display();

    return 0;
}
