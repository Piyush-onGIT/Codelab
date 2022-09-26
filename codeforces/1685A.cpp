/** author: kicker
*   created: 06-09-2022 13:41
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
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    sort(a, a + n);

    vll first, second, ans;
    loop(i, 0, n / 2) first.pb(a[i]);
    loop(i, ceil(n / (double) 2), n) second.pb(a[i]);

    ll c1 = 0, c2 = 0;
    while (c1 < first.size()) {
    	ans.pb(first[c1]);
    	if (n % 2 and ans.size() == n / 2) ans.pb(a[n / 2]);
    	ans.pb(second[c2]);
    	if (n % 2 and ans.size() == n / 2) ans.pb(a[n / 2]);
    	c1++; c2++;
    }

    loop(i, 0, n) {
    	ll before, after;
    	if (i == 0) before = n - 1;
    	else before = i - 1;

    	if (i == n - 1) after = 0;
    	else after = i + 1;

    	if ((ans[i] > ans[before] and ans[i] > ans[after]) or (ans[i] < ans[before] and ans[i] < ans[after])) continue;
    	else {
    		cout << "NO\n";
    		return;
    	}
    }
    cout << "YES\n";
    print(ans);
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