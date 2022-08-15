/** author: kicker
*   created: 14-08-2022 11:54
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

bool there(vll a, ll n) {
    loop(i, 0, a.size()) if (a[i] == n) return true;
    return false;
}

ll freq(ll a[], ll n) {
    ll c = 0;
    loop(i, 0, n) if (a[i] == n) c++;
    return c;
}

void solve() {
    ll n;
    cin >> n;
    set<ll> dist;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    loop(i, 0, n - 1) {
        if (dist.count(a[i])) {
            a[i] = 0;
            rrep(j, i - 1, 0) {
                if (a[j] == 0) break;
                dist.insert(a[j]);
            }
        }
        if (dist.count(a[i + 1])) {
            a[i + 1] = 0;
            rrep(j, i, 0) {
                if (a[j] == 0) break;
                dist.insert(a[j]);
            }
        }
        if (a[i] > a[i + 1]) {
            dist.insert(a[i]);
            a[i] = 0;
            rrep(j, i - 1, 0) {
                if (a[j] == 0) break;
                dist.insert(a[j]);
            }
        }
    }

    cout << dist.size() line;
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