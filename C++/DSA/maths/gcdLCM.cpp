// gcd and lcm
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cout << gcd(6, 12) << endl;
    cout << lcm(6, 12) << endl;
}