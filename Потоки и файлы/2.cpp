#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileCopy {
public:
    void run() {
        string sourceFileName, destFileName;

        cout << "Введите имя исходного файла (без расширения): ";
        cin >> sourceFileName;
        sourceFileName += ".txt";

        cout << "Введите имя файла назначения (без расширения): ";
        cin >> destFileName;
        destFileName += ".txt"; 
        saveDataToFile(sourceFileName);
        copyFile(sourceFileName, destFileName);
    }

private:
    void saveDataToFile(const string& fileName) {
        ofstream outFile(fileName);

        if (!outFile) {
            cerr << "Не удалось открыть файл для записи: " << fileName << endl;
            return;
        }

        string data;
        cout << "Введите данные для записи в файл (введите 'END' для завершения):\n";

        while (true) {
            getline(cin, data);
            if (data == "END") break;
            outFile << data << endl; 
        }

        outFile.close();
        cout << "Данные успешно сохранены в файл: " << fileName << endl;
    }

    void copyFile(const string& sourceFileName, const string& destFileName) {
        ifstream inFile(sourceFileName);

        if (!inFile) {
            cerr << "Не удалось открыть исходный файл для копирования: " << sourceFileName << endl;
            return;
        }

        ofstream outFile(destFileName);

        if (!outFile) {
            cerr << "Не удалось открыть файл назначения для записи: " << destFileName << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            outFile << line << endl; 
        }

        inFile.close();
        outFile.close();
        cout << "Файл успешно скопирован: " << sourceFileName << " → " << destFileName << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 
    FileCopy copier;
    copier.run();
    return 0;
}
