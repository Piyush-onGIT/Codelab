/** author: kicker
*   created: 19-09-2022 12:17
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << endl
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rrep(i, x, n)                       for (ll i = x; i >= n; i--)
#define f                                   first
#define s                                   second
#define all(x)                              x.begin(), x.end()
#define vi                                  vector<int>
#define vs                                  vector<string>
#define vll                                 vector<long long>
#define pb                                  push_back
#define pf                                  push_front
#define vc                                  vector<char>
#define sll                                 set<ll>
#define mll                                 map<ll, ll>
#define pqMax                               priority_queue<ll>
#define pqMin                               priority_queue<int, vector<ll>, greater<ll>>


template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }
template <typename T> void parr(T a[], ll n) { loop(i, 0, n) cout << a[i] << " "; cout line; }
template <typename T> void print(vector<T> v) { loop(i, 0, v.size()) cout << v[i] << " "; cout line; }

void solve() {
    ll n, m = 1e9 + 7;
    cin >> n;
    char grid[n][n];

    loop(i, 0, n) loop(j, 0, n) cin >> grid[i][j];

    // dp[i][j] = steps to go from (0, 0) to (i, j)
    ll dp[n][n];
    dp[0][0] = 1;
    loop(i, 0, n) {
    	loop(j, 0, n) if (grid[i][j] == '*') dp[i][j] = 0;
    }

    loop(i, 0, n) {
    	loop(j, 0, n) {
    		if (i == 0 and j == 0) continue;
    		if (grid[i][j] == '*') continue;
    		ll x = dp[i - 1][j], y = dp[i][j - 1];

    		if (i - 1 < 0) x = 0;
    		if (j - 1 < 0) y = 0;

    		dp[i][j] = ((x % m) + (y % m)) % m;
    	}
    }

    cout << dp[n - 1][n - 1] line;
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