/** author: kicker
*   created: 16-08-2022 20:02
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
template <typename T> void parr(T a[], ll n) { loop(i, 0, n) cout << a[i] << " "; cout line; }
template <typename T> void print(vector<T> v) { loop(i, 0, v.size()) cout << v[i] << " "; cout line; }

void solve() {
    ll n, k;
    cin >> n >> k;

    if (k == 0) {
    	cout << "NO\n";
    	return;
    }
    if (k % 2 == 0) {
    	ll s = 2;
    	vector<pair<ll, ll>> ans;
    	loop(i, s, n + 1) {
    		ll a = i, b = i - 1;
    		if (a % 4 == 0) ans.pb({b, a});
    		else if ((a + k) % 4 == 0) ans.pb({a, b});
    		else {
    			cout << "NO\n";
    			return;
    		}
    		i++;
    	}
		cout << "YES\n";
    	loop(i, 0, ans.size()) {
    		cout << ans[i].f << " " << ans[i].s line;
    	}
    }
    else {
    	cout << "YES\n";
    	ll s = 1;
    	loop(i, s, n + 1) {
    		cout << i << " " << i + 1 line;
    		i++;
    	}
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