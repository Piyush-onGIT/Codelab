// count number of divisors
#include <bits/stdc++.h>
using namespace std;

int cntDiv(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i != n / i) cnt += 2;
        else cnt++;
    }
    return cnt;
}

int main() {
    int n = 10;
    // below code has time complexity: rt(1) + rt(2) + ... + rt(n)
    // close to n * rt(n)
    for (int i = 1; i <= n; i++) {
        int iDiv = cntDiv(i);
    }
    
    // optimised solution, iterate on multiples
    vector<int> div(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            div[j]++;
        }
    }
    // time complexity: (n/1) + (n/2) + ... + (n/n) = close to n(log n)
    cout << div[6] << endl;
    // div[i] stores number of divisors of i
}