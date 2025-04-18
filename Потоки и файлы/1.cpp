#include <iostream>
#include <fstream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0f) {}

    Distance(int ft, float in) : feet(ft), inches(in) {}

    void input() {
        cout << "\nÂâåäèòå ôóòû: ";
        cin >> feet;
        cout << "Ââåäèòå äþéìû: ";
        cin >> inches;
    }

    void output() const {
        cout << feet << "\'-" << inches << "\"";
    }

    void save(ofstream& out) const {
        out << feet << " " << inches << endl;
    }

    bool load(ifstream& in) {
        return static_cast<bool>(in >> feet >> inches);
    }
};

class DistanceApp {
private:
    const string filename = "distances.txt";

public:
    void start() {
        addDistances();
        displayAll();
    }

private:
    void addDistances() {
        ofstream fout(filename, ios::app);
        int choice = 1;

        while (choice == 1) {
            Distance d;
            d.input();
            d.save(fout);

            cout << "Õîòèòå ââåñòè åù¸ îäíî ðàññòîÿíèå? (1 — äà, 0 — íåò): ";
            cin >> choice;

            while (choice != 0 && choice != 1) {
                cout << "Íåâåðíûé ââîä. Ââåäèòå 1 äëÿ ïðîäîëæåíèÿ èëè 0 äëÿ âûõîäà: ";
                cin >> choice;
            }
        }

        fout.close();
    }

    void displayAll() {
        ifstream fin(filename);
        if (!fin) {
            cout << "Îøèáêà ïðè îòêðûòèè ôàéëà!\n";
            return;
        }

        Distance d;
        int count = 0;

        cout << "\nÑîõðàí¸ííûå ðàññòîÿíèÿ:\n";

        while (d.load(fin)) {
            cout << ++count << ") ";
            d.output();
            cout << endl;
        }

        fin.close();
    }
};
int main() {
    setlocale(LC_ALL,"Rus");
    DistanceApp app;
    app.start();
    return 0;
}
