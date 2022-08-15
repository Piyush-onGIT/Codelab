// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class A {
    public:
        int a;
        void display() {
            cout << "level 1\n";
        }
};

class B : public A {
    public:
        int b;
        void disp() {
            cout << "Level 2\n";
        }
};

class C : public B {
    public:
        int c;
        void disp3() {
            cout << "Level 3\n";
        }
};

int main() {
    A a; B b; C c;
    a.display();
    b.display();
    c.disp();
}