/** author: kicker
*   time: 18-06-2022 20:03
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
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    ll mx = INT_MIN;

    loop(i, 0, n) {
    	loop(j, 0, m) {
    		cin >> a[i][j];
    		mx = max(mx, a[i][j]);
    	}
    }

    ll r = 0, c = 0;
    loop(i, 0, n) {
    	loop(j, 0, m) {
    		if (a[i][j] == mx) {
    			r = i;
    			c = j;
    			break;
    		}
    	}
    }
    r++; c++;
    r = max(r, n + 1 - r);
    c = max(c, m + 1 - c);
    ll ans = r * c;
	cout << ans line;
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