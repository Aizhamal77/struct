#include <iostream>
using namespace std;

class Time {
private:
    int hrs, mins, secs;

public:
    Time() : hrs(0), mins(0), secs(0) {}  

    Time(int h, int m, int s) : hrs(h), mins(m), secs(s) {} 

    void display() const {  
        cout << hrs << ":" << mins << ":" << secs;
    }

    Time operator + (const Time& t2) {  
        int s = secs + t2.secs;  
        int m = mins + t2.mins; 
        int h = hrs + t2.hrs;    
        if (s > 59) { 
            s -= 60;
            m++;
        }
        if (m > 59) { 
            m -= 60;
            h++;
        }
        return Time(h, m, s);  
    }
};

int main() {
    setlocale(LC_ALL, "Rus");  

    Time time1(5, 59, 59);  
    Time time2(4, 30, 30);  
    Time time3;             

    time3 = time1 + time2;  

    cout << "\ntime3 = ";
    time3.display();  
    cout << endl;

    return 0;
}
