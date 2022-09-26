/** author: kicker
*   created: 22-09-2022 19:59
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << "\n"
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rep(i, x, n)                       for (int i = x; i < n; i++)
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
    int m = 1000000007;
    int n, sum;
    cin >> n >> sum;
    vi a(n + 1);
    a[0] = 0;
    loop(i, 1, n + 1) cin >> a[i];
 
    vector<vector<int>> dp(n + 1, vi(sum + 1, 0));
    dp[0][0] = 1;
    // dp[i][j] = number of ways to make sum = x using first i coins
 
    rep(i, 1, n + 1) {
        rep(j, 0, sum + 1) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0) (dp[i][j] += dp[i][j - a[i]]) %= m;
        }
    }
 
    cout << dp[n][sum] line;
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