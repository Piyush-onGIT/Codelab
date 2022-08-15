/** author: kicker
*   created: 24-07-2022 12:37
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

ll ceilingNum(vll arr, ll target) {
    ll start = 0, end = arr.size() - 1;
    ll mid;
    if (target > arr[arr.size() - 1]) return -1;         // no ceiling found
    while (start <= end) {
        mid = start + (end - start)/2;          // to make sure it can't go out of int limit
        if (arr[mid] == target) return mid;     // element found
        else if (arr[mid] > target) {           // element lies in the left side of mid
            end = mid - 1;
        }
        else {
            start = mid + 1;                    // element lies in the right side of mid
        }
    }
    return start;                          // start will be poiting to ceiling of number
    // in the end start will be pointing to the number which is just greater than the target
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    loop(i, 0, n) cin >> a[i];

    vll b = a;
    sort(all(b));

    map<ll, vll> ind;
    loop(i, 0, n) {
        ind[a[i]].pb(i);
    }

    map<ll, vll>::iterator i = ind.begin();
    vll ocur = i -> s;
    i++;
    for (i; i != ind.end(); i++) {
        ll ceil = ceilingNum(i -> s, ocur[ocur.size() - 1]);
        if (ceil == -1) {
            ocur.insert(ocur.end(), all(i -> s));
        }
        else {
            loop(j, ceil, (i -> s).size()) ocur.pb((i -> s)[j]);
            loop(j, 0, ceil) ocur.pb((i -> s)[j]);
        }
    }

    ll s = 0, e = 1;
    while (e < n) {
        if (ocur[s] > ocur[e]) break;
        s++; e++;
    }

    vll left, right;
    loop(i, 0, s + 1) left.pb(ocur[i]);
    loop(i, e, n) right.pb(ocur[i]);

    if (is_sorted(all(left)) && is_sorted(all(right))) cout << "YES\n";
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