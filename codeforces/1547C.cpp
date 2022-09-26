/** author: kicker
*   created: 16-08-2022 13:13
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
    ll n, m, k;
    cin >> k >> n >> m;
    ll a[n], b[m], c[n + m];
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, m) cin >> b[i];

    loop(i, 0, n) c[i] = a[i];
    loop(i, 0, m) c[i + n] = b[i];

    sort(c, c + n + m);
    ll z = 0;
    loop(i, 0, n + m) if (c[i] == 0) z++;

    ll zm = 0, zp = 0;
    loop(i, 0, n) if (a[i] == 0) zm++;
    loop(i, 0, m) if (b[i] == 0) zp++;

    if (z >= c[n + m - 1] - k) {
    	vll ans;
    	ll p1 = 0, p2 = 0;
    	while (p1 < n && p2 < m) {
    		if (a[p1] == 0 && b[p2] == 0) {
    			ans.pb(0); ans.pb(0);
    			k += 2;
    			p1++; p2++;
    		}
    		else if (a[p1] == 0 && b[p2] != 0) {
    			ans.pb(0);
    			k++;
    			p1++;
    		}
    		else if (a[p1] != 0 && b[p2] == 0) {
    			ans.pb(0);
    			k++;
    			p2++;
    		}
    		else {
    			if (a[p1] <= k and b[p2] <= k) {
    				ans.pb(a[p1]); ans.pb(b[p2]);
    				p1++; p2++;
    			}
    			else if (a[p1] <= k) {
    				ans.pb(a[p1]);
    				p1++;
    			}
    			else if (b[p2] <= k) {
    				ans.pb(b[p2]);
    				p2++;
    			}
    			else {
    				cout << -1 line;
    				return;
    			}
    		}
    	}
    	while (p1 < n) {
    		if (a[p1] == 0) {
    			ans.pb(a[p1]);
    			k++;
    		}
    		else {
    			if (a[p1] <= k) ans.pb(a[p1]);
    			else {
    				cout << -1 line;
    				return;
    			}
    		}
    		p1++;
    	}
    	while (p2 < m) {
    		if (b[p2] == 0) {
    			ans.pb(b[p2]);
    			k++;
    		}
    		else {
    			if (b[p2] <= k) ans.pb(b[p2]);
    			else {
    				cout << -1 line;
    				return;
    			}
    		}
    		p2++;
    	}
    	print(ans);
    }
    else cout << -1 line;
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