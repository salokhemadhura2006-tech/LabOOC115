
#include <iostream>
using namespace std;

int main() {
    int h[20], n, r = 0, error = 0;

    cout << "Enter total number of bits: ";
    cin >> n;

    cout << "Enter received Hamming code bits (left to right): ";
    for (int i = n; i >= 1; i--)
        cin >> h[i];

    // Calculate number of parity bits
    while ((1 << r) <= n)
        r++;

    // Check parity bits
    for (int p = 1; p <= n; p *= 2) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (i & p)
                count += h[i];
        }

        if (count % 2 != 0)
            error += p;
    }

    // Detect and correct error
    if (error == 0) {
        cout << "No error detected.";
    }
    else if (error <= n) {
        cout << "\nError at position: " << error;
        h[error] = 1 - h[error];

        cout << "\nCorrected Hamming code: ";
        for (int i = n; i >= 1; i--)
            cout << h[i];
    }
    else {
        cout << "Invalid error position.";
        return 1;
    }

    // Extract original data bits
    cout << "\nData bits: ";
    for (int i = n; i >= 1; i--) {
        if ((i & (i - 1)) != 0)
            cout << h[i];
    }

    cout << endl;
    return 0;
}