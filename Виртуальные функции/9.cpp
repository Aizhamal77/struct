#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Horse {
protected:
    float pos;   
    float spd;   

public:
    Horse() : pos(0), spd(10.0f) {}  

    virtual void tick() {
        pos += spd;
    }

    virtual float getPos() const {
        return pos;
    }

    virtual float getSpd() const {
        return spd;
    }

    virtual ~Horse() {}
};

class CompHorse : public Horse {
private:
    static constexpr float closeDist = 0.1f; 
    static vector<Horse*> horsesList;  

public:
    CompHorse() : Horse() {}

    void tick() override {
        Horse::tick(); 

        for (auto& other : horsesList) {
            if (other != this) {
                float dist = fabs(pos - other->getPos());
                if (dist < closeDist) {
                    spd += 0.5f;  
                    break;
                }
            }
        }

        bool leader = true;
        for (auto& other : horsesList) {
            if (other != this && other->getPos() > pos) {
                leader = false;
                break;
            }
        }

        if (leader && pos < 100.0f) {  
            spd += 0.2f;
        }
    }

    static void HorsesList(vector<Horse*>& horses) {
        horsesList = horses;  
    }

    ~CompHorse() {}
};

vector<Horse*> CompHorse::horsesList; 

class RaceTrack {
private:
    vector<Horse*> horses;

public:
    void add(Horse* h) {
        horses.push_back(h);
    }

    void start() {
        CompHorse::HorsesList(horses);  

        for (int i = 0; i < 50; i++) { 
            cout << "Tick " << i + 1 << ":\n";
            for (auto& h : horses) {
                h->tick();
                cout << "Horse position: " << h->getPos() << ", Speed: " << h->getSpd() << endl;
            }
            cout << "----------------------\n";
        }
    }

    void show() {
        Horse* h1 = new Horse();
        Horse* h2 = new CompHorse(); 
        Horse* h3 = new CompHorse();  

        add(h1);
        add(h2);
        add(h3);
        start();

        delete h1;
        delete h2;
        delete h3;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    RaceTrack track;
    track.show();
    return 0;
}
