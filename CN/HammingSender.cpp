
#include <iostream>
using namespace std;

int main() {
    int d[10], h[20] = {0};
    int m, r = 0, n;

    cout << "Enter number of data bits: ";
    cin >> m;

    cout << "Enter data bits: ";
    for (int i = 0; i < m; i++)
        cin >> d[i];

    // Calculate redundant bits
    while ((1 << r) < (m + r + 1))
        r++;

    n = m + r;

    // Place data bits
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0)
            h[i] = d[j++];
    }

    // Calculate parity bits (even parity)
    for (int p = 1; p <= n; p *= 2) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & p) && i != p)
                count += h[i];
        }

        h[p] = count % 2;
    }

    // Display Hamming code
    cout << "Hamming code: ";
    for (int i = n; i >= 1; i--)
        cout << h[i];

    return 0;
}