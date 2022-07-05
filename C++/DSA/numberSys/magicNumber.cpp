#include <bits/stdc++.h>
using namespace std;

// magic number, amazon question
// questions written in copy
int main() {
    int n = 6;
    int base = 5;
    int ans = 0;
    while (n > 0) {
        int last = n & 1;       // extract last bit
        ans += last * base;
        base *= 5;
        n = n >> 1;             // remove last bit
    }
    cout << ans;
}