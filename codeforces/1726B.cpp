/** author: kicker
*   created: 06-09-2022 20:04
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
    ll n, m;
    cin >> n >> m;

    if (n > m) {
    	cout << "NO\n";
    	return;
    }
    if (m % n == 0) {
    	cout << "YES\n";
    	loop(i, 0, n) cout << m / n sp;
    	cout line;
    	return;
    }
    if (m % 2 and n % 2 == 0) {
    	cout << "NO\n";
    	return;
    }
    else {
    	if ((n - 1) % 2 == 0) {
    		cout << "YES\n";
    		ll rep = m / n;
    		ll s = rep * (n - 1);
    		loop(i, 0, n - 1) cout << rep sp;
    		cout << m - s line;
    	}
    	else {
    		cout << "YES\n";
    		ll rep = m / n;
    		loop(i, 0, n - 2) cout << 1 sp;
    		m -= (n - 2);
    		m /= 2;
    		cout << m sep m line;
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