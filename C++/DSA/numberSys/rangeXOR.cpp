// xor of numbers from a to b
#include <bits/stdc++.h>
using namespace std;

// explanation in copy
int rangeXOR(int x) {
    if (x % 4 == 0) return x;
    else if (x % 4 == 1) return 1;
    else if (x % 4 == 2) return x + 1;
    else return 0;
}

int main() {
    int a = 3;
    int b = 9;
    int ans = rangeXOR(b) ^ rangeXOR(a - 1);
    
    int ans1;
    // brute force approach, it will give TLE
    for (int i = a; i <= b; i++) ans1 ^= i;
    cout << ans << endl;
    cout << ans1 << endl;
}