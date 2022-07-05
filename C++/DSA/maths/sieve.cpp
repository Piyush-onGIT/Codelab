#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<bool> &primes) {
    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {       // if i is prime
            for (int j = 2 * i; j <= n; j += i) {
                primes[j] = false;       // set the multiples of i to false
            }
        }
    }
}

bool isPrime(int n) {
    vector<bool> primes(n + 1, 1);
    sieve(n, primes);
    return primes[n];
}

int main() {
    int n = 40;
    vector<bool> primes(n + 1, 1);
    sieve(n, primes);
    primes[i] = true => i is prime
    for (int i = 2; i <= n; i++) {
        if (primes[i]) cout << i << " ";
    }
    cout << endl;
}