/** author: kicker
*   created: 24-09-2022 20:23
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << "\n"
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rep(i, x, n)                        for (int i = x; i < n; i++)
#define rrep(i, x, n)                       for (ll i = x; i >= n; i--)
#define f                                   first
#define s                                   second
#define all(x)                              x.begin(), x.end()
#define dsort(x)                            sort(all(x), greater<ll>())
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
    vll a(n), b(n);

    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];

    vll a1 = a, b1 = b;
    sort(all(a1));
    sort(all(b1));

    vector<pair<ll, ll>> ans;

    ll flag = 0;
	loop(i, 0, n) {
		loop(j, i, n) {
			if (a1[i] == a[j] and b1[i] == b[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				if (i != j) {
					ans.pb({i + 1, j + 1});
				}
				break;
			}
		}
		if (a1[i] != a[i] or b1[i] != b[i]) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << -1 line;
		return;
	}

    cout << ans.size() line;
    for (auto i : ans) {
    	cout << i.f sep i.s line;
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