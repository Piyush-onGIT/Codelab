// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

template <class T>
class A {
    public:
        T a;
        T f() {
            return a * a;
        }
};

int main() {
    A<int> b;
    b.a = 10;
    cout << b.f() << endl;
}