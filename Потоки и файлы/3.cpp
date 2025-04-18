#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileSize {
public:
    void run() {
        string fileName;

        cout << "Ââåäèòå èìÿ ôàéëà (áåç ğàñøèğåíèÿ): ";
        cin >> fileName;
        fileName += ".txt";

        printFileSize(fileName);
    }

private:
    void printFileSize(const string& fileName) {
        ifstream file(fileName, ios::binary);

        if (!file) {
            cerr << "Îøèáêà: íå óäàëîñü îòêğûòü ôàéë " << fileName << endl;
            return;
        }

        file.seekg(0, ios::end);  
        streampos size = file.tellg(); 

        cout << "Ğàçìåğ ôàéëà " << fileName << " ñîñòàâëÿåò: " << size << " áàéò.\n";

        file.close(); 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    FileSize fileSize;
    fileSize.run();
    return 0;
}
