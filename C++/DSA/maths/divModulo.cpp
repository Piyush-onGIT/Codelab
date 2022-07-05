// division in modulo
#include <bits/stdc++.h>
using namespace std;

// (a^b) % m
// binary exponentiation or binPow
// O(log power)

int pw(int base, int power, int m) {
    if (power == 0) return 1 % m;
    if (power % 2 == 0) {
        int t = pw(base, power / 2, m);
        return 1ll * ((t * t) % m);
    }
    else {
        int t = pw(base, (power - 1) / 2, m);
        t = 1ll * t * t;
        return (t * base) % m;
    }
}

int main() {
    int a = 156;
    int b = 4;
    int m = 17;
    
    int res1 = (a / b) % m;
    
    a = a % m;
    int inv_b = pw(b, m - 2, m);        // fermat's little theorem
    int res2 = a * inv_b % m;
    
    cout << res1 << " " << res2 << endl;
}