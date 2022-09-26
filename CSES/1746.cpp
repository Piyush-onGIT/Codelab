/** author: kicker
*   created: 24-09-2022 12:58
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << "\n"
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rep(i, x, n)                        for (int i = x; i < n; i++)
#define rrep(i, x, n)                       for (ll i = x; i >= n; i--)
#define f                                   first
#define s                                   second
#define all(x)                              x.begin(), x.end()
#define dsort(x)                            sort(all(x), greater<ll>())
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
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, 0, n) cin >> a[i];
 
    vector<vi> dp(n + 1, vi(m + 1, 0));
    // dp[i][j] => number of ways to fix array till i if a[i] = j
    // dp[i][j] = number of ways that you can fix array till i - 1 with
    //            j - 1, j, j + 1 to make adjacent diff <= 1
 
    if (a[0] == 0) {
        loop(i, 1, m + 1) dp[1][i] = 1;
    }
    else {
        loop(i, 1, m + 1) dp[1][i] = 0;
        dp[1][a[0]] = 1;
    }
 
    loop(i, 2, n + 1) {
        loop(j, 1, m + 1) {
            if (a[i - 1] != 0) {
                ll t = a[i - 1];
                dp[i][t] = dp[i - 1][t] % mod;
                if (t - 1 >= 1) (dp[i][t] += dp[i - 1][t - 1]) %= mod;
                if (t + 1 <= m) (dp[i][t] += dp[i - 1][t + 1]) %= mod;
            }
            else {
                dp[i][j] = dp[i - 1][j] % mod;
                if (j - 1 >= 1) (dp[i][j] += dp[i - 1][j - 1]) %= mod;
                if (j + 1 <= m) (dp[i][j] += dp[i - 1][j + 1]) %= mod;
            }
        }
    }
 
    ll ans = 0;
    loop(i, 1, m + 1) (ans += dp[n][i]) %= mod;
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
    // cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}