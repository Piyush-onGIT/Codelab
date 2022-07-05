#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 9;      // 1001 in binary
    int cnt = 0;
    
    // M-1
    while (n > 0) {
        cnt++;
        n -= n & -n;
    }
    cout << cnt << endl;
    
    // M-2
    while (n > 0) {
        cnt++;
        n = n & (n - 1);
    }
    cout << cnt << endl;
}