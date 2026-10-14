#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("sample.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    while (fin.get(ch)) {
        fout.put(ch);
    }

    cout << "File copied successfully!" << endl;

    fin.close();
    fout.close();

    return 0;
}