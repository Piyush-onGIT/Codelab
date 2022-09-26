/** author: kicker
*   created: 17-08-2022 13:29
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define sep << " " <<
#define sp << " "
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define rrep(i, x, n) for (ll i = x; i >= n; i--)
#define all(x) x.begin(), x.end()
#define vll vector<long long>
#define pb push_back

template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }
template <typename T> void parr(T a[], ll n) { loop(i, 0, n) cout << a[i] << " "; cout line; }
template <typename T> void print(vector<T> v) { loop(i, 0, v.size()) cout << v[i] << " "; cout line; }

void solve() {
    ll n;
    cin >> n;
    vll neg, pos;
    ll a;
    loop(i, 0, n) {
    	cin >> a;
    	if (a > 0) pos.pb(a);
    	else neg.pb(a);
    }
    
    if (pos.size() == 0) { cout << neg.size() line; return; }
    if (neg.size() == 0) { cout << 1 line; return; }

    vll n1 = neg;
    sort(all(n1));
    sort(all(pos));

    ll flag = 1;
    loop(i, 0, n1.size() - 1) {
    	if (abs(n1[i] - n1[i + 1]) < pos[0]) {
    		flag = 0;
    		break;
    	}
    }

    if (flag) cout << neg.size() + 1 line;
    else cout << neg.size() line;
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