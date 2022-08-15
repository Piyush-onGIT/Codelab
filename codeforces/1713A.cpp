/** author: kicker
*   created: 07-08-2022 13:34
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

template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    vll x1, x2, y1, y2;
    while (n--) {
    	ll a, b;
    	cin >> a >> b;
    	if (a == 0) {
    		if (b < 0) x2.pb(abs(b));
    		else x1.pb(b);
    	}
    	else {
    		if (a < 0) y2.pb(abs(a));
    		else y1.pb(a);
    	}
    }

    sort(all(x1));
    sort(all(x2));
    sort(all(y1));
    sort(all(y2));

    if (x1.size() != 0) ans += x1[x1.size() - 1] * 2;
    if (x2.size() != 0) ans += x2[x2.size() - 1] * 2;
    if (y1.size() != 0) ans += y1[y1.size() - 1] * 2;
    if (y2.size() != 0) ans += y2[y2.size() - 1] * 2;

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