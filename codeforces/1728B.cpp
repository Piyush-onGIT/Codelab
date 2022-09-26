/** author: kicker
*   created: 08-09-2022 19:58
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
    vll a;

    if (n == 1) {
    	cout << 1 line;
    	return;
    }

    if (n == 2) {
    	cout << 2 sep 1 line;
    	return;
    }

    if (n == 3) {
    	cout << "2 1 3\n";
    	return;
    }

    loop(i, 1, n - 1) a.pb(i);

    if (n % 2 == 0) {
    	sort(all(a));
    	reverse(all(a));
	    loop(i, 0, a.size()) cout << a[i] sp;
	    cout << n - 1 sep n line;
	}
	else {
		if (n == 5) {
			cout << "1 2 3 4 5\n";
			return;
		}
		vll b;
		loop(i, 1, n + 1) {
			if (i == 1 or i == 2 or i == 3 or i == n - 1 or i == n) continue;
			else b.pb(i);
		}
		sort(all(b));
		reverse(all(b));

		cout << "1 2 3 ";
		loop(i, 0, b.size()) cout << b[i] sp;
		cout << n - 1 sep n line;
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