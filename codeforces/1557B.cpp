/** author: kicker
*   created: 16-08-2022 01:42
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

ll binarySearch(vll a, ll key) {
    ll s = 0, e = a.size() - 1;
    while (s <= e) {
        ll mid = s + (e - s) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    map<ll, ll> index;
    loop(i, 0, n) cin >> a[i];

    vll b = a;
    sort(all(b));
    loop(i, 0, n) index[b[i]] = i;

    ll subs = 0;
    loop(i, 1, n) {
        ll pos = index[a[i]];
    	if (b[pos - 1] != a[i - 1]) subs++;
    }
    subs++;
    if (subs <= k) cout << "YES\n";
    else cout << "NO\n";
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