/** author: kicker
*   created: 12-09-2022 19:47
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
    string s;
    cin >> s;
    ll n = s.size();
    map<char, set<ll>> cnt;

    ll tmp = 0;
    

    if (s[n - 1] >= s[0]) {
    	loop(i, 0, n - 1) {
    	if (s[i] >= s[0] and s[i] <= s[n - 1]) cnt[s[i]].insert(i);
    }
    	vll ans;
    	auto i = cnt.begin();

    	for (i; i != cnt.end(); i++) {
    		if (i -> f == s[0]) break;
    	}
	    for (i; i != cnt.end(); i++) {
	    	for (auto j : i -> s) ans.pb(j + 1);
	    }
		ans.pb(n);
		ll cost = abs(s[0] - s[n - 1]);
		cout << cost sep ans.size() line;
		print(ans);
	}
	else {
		loop(i, 0, n - 1) {
    	if (s[i] <= s[0] and s[i] >= s[n - 1]) cnt[s[i]].insert(i);
    }
		ll tmp = 0;
		vll ans;
		auto itr = cnt.rbegin();
		 for (itr; itr != cnt.rend(); itr++) {
		 	if (itr -> f == s[0]) break;
		 }

		 for (itr; itr != cnt.rend(); itr++) {
		 	for (auto j : itr -> s) ans.pb(j + 1);
		 }
		ans.pb(n);
		ll cost = abs(s[0] - s[n - 1]);
		cout << cost sep ans.size() line;
		print(ans);
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