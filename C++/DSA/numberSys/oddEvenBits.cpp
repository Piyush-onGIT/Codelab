#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
    return (n & 1);         // returns 1(true) for odd number
}

bool isEven(int n) {
    return !(n & 1);        // returns 1(true) for even number
}

int main() {
    bool res = isEven(31);
    cout << res << endl;
}