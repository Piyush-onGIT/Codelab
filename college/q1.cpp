// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class A {
	public:
		int a;
		A operator + (const A &obj) {
			A ans;
			ans.a = a + obj.a;
			return ans;
		}
};

class B : public A {
	public:
		int a;
		B operator + (const B &obj) {
			B ans;
			ans.a = a - obj.a;
			return ans;
		}
		
};

int main() {
	B a1, a2, a3;
	a1.a = 1, a2.a = 2, a3.a = 4;
	a3 = a1 + a2;
	cout << a3.a;
}