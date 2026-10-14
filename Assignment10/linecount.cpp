#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream fin("sample..txt");

    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    string line, word;

    while (getline(fin, line)) {
        lines++;
        characters += line.length();

        stringstream ss(line);
        while (ss >> word) {
            words++;
        }
    }

    cout << "Number of lines: " << lines << endl;
    cout << "Number of words: " << words << endl;
    cout << "Number of characters: " << characters << endl;

    fin.close();
    return 0;
}