/** author: kicker
*   created: 16-08-2022 23:37
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
    string s;
    cin >> s;

    ll sum = INT_MIN, f = 0, e = 0;
    rrep(i, s.size() - 1, 1) {
    	sum = (s[i] - '0') + (s[i - 1] - '0');
    	if (sum >= 10) {
    		loop(j, 0, i - 1) cout << s[j];
    		cout << sum;
    		loop(j, i + 1, s.size()) cout << s[j];
    		cout line;
    		return;
    	}
    	else {
    		if ((s[i] - '0') + (s[i - 1] - '0') > sum) {
    			sum = (s[i] - '0') + (s[i - 1] - '0');
    			f = i - 1; e = i;
    		}
    	}
    }
    loop(i, 0, f) cout << s[i];
    cout << sum;
    loop(i, f + 2, s.size()) cout << s[i];
    cout line;
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