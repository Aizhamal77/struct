#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileSize {
public:
    void run() {
        string fileName;

        cout << "������� ��� ����� (��� ����������): ";
        cin >> fileName;
        fileName += ".txt";

        printFileSize(fileName);
    }

private:
    void printFileSize(const string& fileName) {
        ifstream file(fileName, ios::binary);

        if (!file) {
            cerr << "������: �� ������� ������� ���� " << fileName << endl;
            return;
        }

        file.seekg(0, ios::end);  
        streampos size = file.tellg(); 

        cout << "������ ����� " << fileName << " ����������: " << size << " ����.\n";

        file.close(); 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    FileSize fileSize;
    fileSize.run();
    return 0;
}
