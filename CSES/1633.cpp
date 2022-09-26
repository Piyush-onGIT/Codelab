/** author: kicker
*   created: 13-09-2022 01:57
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

const ll m = 1000000007;
// vll dp(1000001, -1);
 
// ll dice(ll n, ll c) {
//     if (n < 0) return 0;
//     if (n == 0) {
//         dp[n] = 1;
//         return 1;
//     }
 
//     if (dp[n] != -1) return dp[n];
 
//     for (ll i = 1; i <= 6; i++) {
//         c = ((c % m) + (dice(n - i, 0) % m)) % m;
//     }
//     dp[n] = c;
//     return c;
// }
 
void solve() {
    ll n;
    cin >> n;
    // cout << dice(n, 0) line;

    vll dp(n + 1, 0);
    dp[0] = 1;
 
    loop(i, 1, n + 1) {
        loop(j, 1, 7) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % m;
        }
    }
 
    cout << dp[n] line;

    // space optimization
    vll prev = {0, 0, 0, 0, 0, 1};
    vll crnt(6);

    // dp[1] = d[-5] + dp[-4] + dp[-3] + dp[-1] + dp[0]
    // dp[1] = {0, 0, 0, 0, 0, 1}

    // dp[i] depends on dp[i - 6], dp[i - 5],...,dp[i - 1]
    // so store only prev 6 results

    loop(i, 1, n + 1) {
        loop(j, 1, 6) crnt[j - 1] = prev[j];

        crnt[5] = 0;
        loop(j, 0, 6) crnt[5] += prev[j];
        prev = crnt;
        // crnt[5] = dp[i]
        // crnt[4] = dp[i - 1]
        // ...
        // crnt[0] = dp[i - 5]
    }
    cout << crnt[5] line;
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