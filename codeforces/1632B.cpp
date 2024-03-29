/** author: kicker
*   time: 19-06-2022 13:14
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

ll pairwise(vll per) {
    ll ans = INT_MIN;
    loop(i, 0, per.size() - 1) {
        ll t = per[i] ^ per[i + 1];
        ans = max(ans, t);
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    if (n >= 4) {
        vll per(n);
        vll ans;
        loop(i, 0, n) per[i] = i;

        ll p1 = 0, p2 = 1, x = per[0] ^ per[1];
        loop(i, 0, n - 1) {
            ll t = per[i] ^ per[i + 1];
            if (t > x) {
                p1 = i, p2 = i + 1;
                x = t;
            }
        }

        loop(i, 1, n) {
            if (i == p1) {
                ans.pb(per[i]);
                ans.pb(0);
            }
            else ans.pb(per[i]);
        }
        loop(i, 0, n) cout << ans[i] << " ";
        cout line;
    }
    else if (n == 1) cout << 0 line;
    else if (n == 2) cout << "0 1\n";
    else cout << "2 0 1\n";
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