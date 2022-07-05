/** author: kicker
*   time: 16-06-2022 16:56
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

void solve() {
    ll l, r, a;
    cin >> l >> r >> a;

    if (a == 1) {
        cout << r line;
        return;
    }
    if (a > r) cout << r line;
    else if (a == r) cout << r - 1 line;
    else if (a <= l) {
        if (r % a == 0) {
            ll ans = (r - 1) / a + (r - 1) % a;
            cout << ans line;
        }
        else {
            ll rem = r % a;
            if (r - rem < l) {
                ll ans = r / a + r % a;
                cout << ans line;
                return;
            }
            ll ans = (r - rem - 1) / a + (r - rem - 1) % a;
            cout << max(ans, (r / a + r % a)) line;
        }
    }
    else {
        if (r >= a * 2 - 1) cout << a line;
        else cout << a - 1 line;
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