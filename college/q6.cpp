// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class A {
    public:
        int a, b;
        A() {}
        A(int x, int y) {
            a = x;
            b = y;
        }
};

class B : public A {
    public:
    void add(A &obj) {
        cout << obj.a + obj.b << endl;
    }
};

class C : public B {
    public:
        void sub(A &obj) {
            cout << obj.a - obj.b << endl;
        }
};

class D : public C {
    public:
        void multiply(A &obj) {
            cout << obj.a * obj.b << endl;
        }
};

class E : public D {
    public:
        void div(A &obj) {
            double d = obj.a / (double) obj.b;
            cout << d << endl;
        }
};

int main() {
    A obj(1, 2);
    E o1;
    o1.add(obj);
    o1.sub(obj);
    o1.multiply(obj);
    o1.div(obj);
}