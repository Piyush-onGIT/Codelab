/** author: kicker
*   time: 16-06-2022 20:00
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
#define all(x) x.begin(), x.end()
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
    ll a, b;
    cin >> a >> b;

    if (a == b) {
    	loop(i, 0, a) cout << "10";
    	cout line;
    }
    else if (a > b) {
    	ll rem = a - b;
    	loop(i, 0, rem) cout << "0";
    	a -= rem;
    	loop(i, 0, a) cout << "10";
    	cout line;
    }
    else if (abs(a - b) == 1) {
    	if (a > b) {
    		cout << '0';
    		a--;
    		loop(i, 0, a) cout << "10";
    		cout line;
    	}
    	else {
    		cout << '1';
    		b--;
    		loop(i, 0, b) cout << "01";
    		cout line;
    	}
    }
    else {
    	ll rem = b - a;
    	loop(i, 0, a) cout << "01";
    	b -= a;
    	loop(i, 0, b) cout << "1";
    	cout line;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}