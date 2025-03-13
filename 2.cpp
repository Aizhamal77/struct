#include <iostream> 
using namespace std;
#include <conio.h> 

const char ESC = 27;
const double TOLL = 0.5;

class tollBooth{
private:
    unsigned int totalCars;
    double totalCash;      
public:                 
    tollBooth() : totalCars(0), totalCash(0.0){
    }
    void payingCar() {
        totalCars++; totalCash += TOLL;
    }
    void nopayCar() {
        totalCars++;
    }
    void display()const {
        cout << "\n������: " << totalCars
            << ",������: " << totalCash
            << endl;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");
    tollBooth booth1;       
    char ch;

    cout << "\n������� 0 ��� ������ ��� ������,"
        << "\n 1 ��� ������ ������������ ������,"
        << "\n Esc ��� ������.\n ";
    do {
        ch = getche();        
        if (ch == '0')     
            booth1.nopayCar();
        if (ch == '1')       
            booth1.payingCar();
    } while (ch != ESC);    
    booth1.display();       
    return 0;
}