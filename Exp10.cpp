// File Handling with C++ using ifstream & ofstream
// To write content in file and then read the content

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Creation of ofstream class object
    ofstream fout;
    string line;

    // Open file in output mode
    fout.open("sample.txt");

    // Execute loop if file successfully opened
    while (fout)
    {
        // Read a line from standard input
        getline(cin, line);

        // Press -1 to exit
        if (line == "-1")
            break;

        // Write line into file
        fout << line << endl;
    }

    // Close the file
    fout.close();

    // Creation of ifstream class object
    ifstream fin;

    // Open file in input mode
    fin.open("sample.txt");

    // Read and display file content until EOF
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    // Close the file
    fin.close();

    return 0;
}