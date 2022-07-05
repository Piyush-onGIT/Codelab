/** author: kicker
*   time: 12-06-2022 20:12
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
    ll n, q;
    cin >> n >> q;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    sort(a, a + n);
    
    vll dp(n);
    dp[n - 1] = a[n - 1];

    rrep(i, n - 2, 0) {
    	dp[i] = dp[i + 1] + a[i];
    }
    reverse(dp.begin(), dp.end());
    
    ll x, y;

    while (q--) {
    	cin >> x >> y;
    	ll buy = dp[x - 1];
    	ll dis = dp[x - y - 1];
    	if (x == y) cout << dp[x - 1] line;
    	else cout << buy - dis line;
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
    // cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}