// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

#include<iostream>
using namespace std;

class A {
  private:
    int a;
  public:
    void display() {
        cout << a;
    }
    friend void fun(A &x);
    friend class B;
};
void fun(A &x){
    x.a = 1;
}

class B {
    public:
        void f(A &a) {
            a.a = 10;
        }
};

int main() {
    A o1;
    fun(o1);
    o1.display();
    cout << endl;

    B o2;
    o2.f(o1);
    o1.display();
}