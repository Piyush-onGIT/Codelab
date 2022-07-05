#include <bits/stdc++.h>
using namespace std;

// (a^b) % m
// binary exponentiation or binPow
// O(log power)

int pw(int base, int power, int m) {
    if (power == 0) return 1 % m;
    if (power % 2 == 0) {
        int t = pw(base, power / 2, m);
        return (1ll * t * t) % m;
    }
    else {
        int t = pw(base, (power - 1) / 2, m);
        t = 1ll * t * t;
        return (t * base) % m;
    }
}

int main() {
    int a = 4;
    int b = 3;
    cout << pw(a, b, 2);
}
