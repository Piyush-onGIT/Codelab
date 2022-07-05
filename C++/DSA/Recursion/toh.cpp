/**
 * @authors: kicker
 * @date: 19:25, 16 March 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll toh(int n, int s, int d, int h) {
	if (n == 1) {
		cout << "move disc " << n << " from tower " << s << " to " << d << endl;
		return 1;
	}
	ll cnt = 1;
	cnt += toh(n - 1, s, h, d);				// take n-1 discs and move it from s to h
	// then take the nth disc(last disc) and move it from s to d
	cout << "move disc " << n << " from tower " << s << " to " << d << endl;
	
	cnt += toh(n - 1, h, d, s);				// then take n-1 discs and move it from h to d
	return cnt;
}

int main() {
	int n = 2;						// no. of discs
	int s = 1, h = 2, d = 3;		// tower numbers
	cout << toh(n, s, d, h) << endl;
}