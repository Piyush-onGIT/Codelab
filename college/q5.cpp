// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class A {
    public:
        int a;
        void display() {
            cout << "Level 1\n";
        }
};

class B {
    public:
        int b;
        void disp() {
            cout << "Level 2\n";
        }
};

class C : public B, public A {
    
};

int main() {
    A a; B b; C c;
    c.display();
    c.disp();
}