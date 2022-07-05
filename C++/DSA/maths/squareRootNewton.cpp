// square root using newton raphson method
#include <bits/stdc++.h>
using namespace std;

double newtonRoot(double n) {
    double root;
    double x = n;       // first guess
    while (true) {
        root = 0.5 * (x + n/x);
        if (abs(root - x) < 1) break;   // to get more precise value decrease this 1
        else x =  root;         // update x
    }
    return root;
}

int main() {
    cout << newtonRoot(40) << endl;
}