/** author: kicker
*   created: 17-09-2022 10:37
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
    ll n, a, b;
    cin >> n >> a >> b;

    set<ll> d1, d2;
    loop(i, 1, n / 2 + 1) d1.insert(i);
    loop(i, n / 2 + 1, n) d2.insert(i);

    if (d1.count(a) and d1.count(b)) cout << -1 line;
    else if (d2.count(a) and d2.count(b)) cout << -1 line;

    else {
    	ll avMn = n - a, avMx = b - 1;

    	if (avMn < n / 2 - 1 or avMx < n / 2 - 1) {
    		cout << -1 line;
    		return;
    	}

    	vll pick;
    	loop(i, 1, n + 1) pick.pb(i);

    	ll s = 0, e = n - 1;
    	while (s < e) {
    		if (s == a - 1 and e == b - 1) {
    			s++; e--;
    			continue;
    		}
    		if (s == a - 1) {
    			s++;
    			continue;
    		}
    		if (e == b - 1) {
    			e--;
    			continue;
    		}
    		swap(pick[s], pick[e]);
    		s++; e--;
    	}
    	ll mn = INT_MAX, mx = INT_MIN;
    	loop(i, 0, n / 2) mn = min(mn, pick[i]);
    	loop(i, n / 2, n) mx = max(mx, pick[i]);

    	if (mn == a and mx == b) print(pick);
    	else cout << -1 line;
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