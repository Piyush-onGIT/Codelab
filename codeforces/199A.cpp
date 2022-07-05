/** author: kicker
*   time: 12-06-2022 03:03
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
#define rrep(i, x, n) for (long long i = x; i >= n; i--)
#define f first
#define s second
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
const int INF = int(2e9) + 99;

void solve() {
    ll n;
    cin >> n;

    if (n <= 3) {
	    if (n == 0) cout << "0 0 0\n";
	    else if (n == 1) cout << "1 0 0\n";
	    else if (n == 2) cout << "1 1 0\n";
	    else if (n == 3) cout << "1 2 0\n";
	    return;
	}

	ll a1 = 0, a2 = 1, a3 = 1, a4 = 2;
    loop(i, 0, n + 1) {
    	ll a5 = a4 + a3;
    	if (a5 == n) {
    		cout << a4 << " " << a2 << " " << a1 line;
    		return;
    	}
    	a1 = a2;
    	a2 = a3;
    	a3 = a4;
    	a4 = a5;
    }
    a1 = 0, a2 = 1;
    loop(i, 0, n) {
    	ll a3 = a1 + a2;
    	if (n == a3 * 2) {
    		cout << a3 << " " << a3 << " 0\n";
    		return;
    	}
    	else if (n == a3 * 3) {
    		cout << a3 << " " << a3 << " " << a3 line;
    		return;
    	}
    	a1 = a2;
    	a2 = a3;
    }
    
    cout << "I'm too stupid to solve this problem\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}