// power of number in O(log(power))

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    int power = 6;          // 110 in binary
    int ans = 1;
    
    while (power > 0) {
        // if last binary dig is 1
        if ((power & 1) == 1) ans *= n;
        power = power >> 1;         // remove the last dig
        n *= n;
    }
    cout << ans;
}