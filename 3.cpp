#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileSize {
public:
    void run() {
        string fileName;

        cout << "Введите имя файла (без расширения): ";
        cin >> fileName;
        fileName += ".txt";

        printFileSize(fileName);
    }

private:
    void printFileSize(const string& fileName) {
        ifstream file(fileName, ios::binary);

        if (!file) {
            cerr << "Ошибка: не удалось открыть файл " << fileName << endl;
            return;
        }

        file.seekg(0, ios::end);  
        streampos size = file.tellg(); 

        cout << "Размер файла " << fileName << " составляет: " << size << " байт.\n";

        file.close(); 
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    FileSize fileSize;
    fileSize.run();
    return 0;
}
