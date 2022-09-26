/** author: kicker
*   created: 06-09-2022 00:45
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
    string s;
    cin >> s;

    ll one = 0, two = 0;
    loop(i, 0, n) {
    	if (s[i] == '1') one++;
    	else two++;
    }

    if (two <= 2 and one != n) cout << "NO\n";
    else {
    	char ans[n][n];
    	loop(i, 0, n) {
    		loop(j, 0, n) {
    			if (i == j) ans[i][j] = 'X';
    			else ans[i][j] = '=';
    		}
    	}

    	vll twos;
    	loop(i, 0, n) if (s[i] == '2') twos.pb(i);

    	loop(i, 0, twos.size()) {
    		ll p1 = twos[i], p2 = twos[(i + 1) % twos.size()];
    		ans[p1][p2] = '+';
    		ans[p2][p1] = '-';
    	}
    	cout << "YES\n";
    	loop(i, 0, n) {
    		loop(j, 0, n) {
    			cout << ans[i][j];
    		}
    		cout line;
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