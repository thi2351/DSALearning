#include <iostream>
using namespace std;

int main() {
    long long int x, y, mod, res = 1;

    // Input x, y, and mod
    cin >> x >> y >> mod;

    // Take x modulo mod to handle large values
    x = x % mod;

    // Modular exponentiation loop
    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y % 2) 
            res = (res * x) % mod;

        // Halve y and square x
        y = y / 2;
        x = (x * x) % mod; 
    }

    // Output the result
    cout << res << endl;

    return 0;
}
