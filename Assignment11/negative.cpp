#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    try {
        if (n < 0) {
            throw n;
        }
        cout << "Number is positive: " << n << endl;
    }
    catch (int x) {
        cout << "Exception caught: Number is negative!" << endl;
    }

    return 0;
}