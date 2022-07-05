/**
 * @author: kicker
 * @date: 10:32, 06 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

void solve() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 4) {
		cout << "2 4 1 3\n";
		return;
	}
	if (n <= 3) {
		cout << "NO SOLUTION\n";
		return;
	}
	ll mxEve, mxOdd;
	if (n % 2) {
		mxOdd = n;
		mxEve = n - 1;
	}
	else {
		mxEve = n;
		mxOdd = n - 1;
	}
	for (ll i = mxEve; i >= 2; i -= 2) cout << i << " ";
	for (ll i = mxOdd; i >= 1; i -= 2) cout << i << " ";
	cout line;
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  
   #ifndef ONLINE_JUDGE
   freopen("../../input.txt", "r", stdin);
   freopen("../../error.txt", "w", stderr);
   freopen("../../output.txt", "w", stdout);
   #endif
  
   ll t;
   // cin >> t;
   t = 1;
   while(t--) {
      solve();
   }
  
   cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}