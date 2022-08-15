/** author: kicker
*   created: 15-08-2022 11:13
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

ll lcm(ll a, ll b) {
	if (a == b) return a;
	ll x = max(a, b);
	ll y = min(a, b);

	for (ll i = x; ; i += x) {
		if (i % y == 0) return i;
	}
}

bool equal(string s) {
	loop(i, 0, s.size() - 1) if (s[i] != s[i + 1]) return false;
	return true;
}

void solve() {
    string s, t;
    cin >> s >> t;

    string min, max;
    if (s.size() < t.size()) {
    	min = s;
    	max = t;
    }
    else {
    	min = t;
    	max = s;
    }

    if (equal(min)) {
    	if (equal(max) && min[0] == max[0]) {
    		ll l = lcm(s.size(), t.size());
    		loop(i, 0, l) cout << min[0];
    		cout line;
    	}
    	else cout << -1 line;
    }
    else {
        ll l = lcm(max.size(), min.size());
        ll l1 = l / min.size(), l2 = l / max.size();
        string min1 = "", max1;

        loop(i, 0, l1) {
            loop(j, 0, min.size()) min1 += min[j];
        }
        loop(i, 0, l2) {
            loop(j, 0, max.size()) max1 += max[j];
        }

        if (min1 == max1) cout << min1 line;
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