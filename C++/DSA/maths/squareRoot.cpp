// simple square root approach
#include <bits/stdc++.h>
using namespace std;

double root(int n, int prec) {
    int s = 0, e = n;
    double rt = 0.0;
    // binary search to find integer part of root
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid > n) e = mid - 1;
        else {
            rt = mid;
            s = mid + 1;
        }
    }
    double inc = 0.1;
    for (int i = 0; i < prec; i++) {
        while (rt * rt <= n) {
            rt += inc;
        }
        // loop breaks when rt * rt > n so decrement it
        rt -= inc;
        inc /= 10;      // 0.1 becomes 0.01 and so on to increase precision
    }
    return rt;
}

int main() {
    int n = 40;
    int prec = 3;
    double rt = root(n, prec);
    printf("%0.3f", rt);
}