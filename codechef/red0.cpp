/** author: kicker
*   time: 11-06-2022 16:23
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
    ll a, b;
    cin >> a >> b;
    
    ll a1 = min(a, b);
    ll b1 = max(a, b);

    if (a1 == 0) {
        if (b1 == 0) cout << 0 line;
        else cout << -1 line;
    }
    else if (a1 == b1) cout << a1 line;
    else {
        ll m = log2(b1 / a1);
        ll op = m;
        ll a2 = a1 * pow(2, m);
        
        if (a2 == b1) cout << op + a2 line;
        else {
            op += a2 - (b1 - a2);
            ll tmp = a2 - (b1 - a2);
            a2 -= tmp;
            b1 -= tmp;
            if (b1 == 2 * a2) {
                op += b1;
                op++;
                cout << op line;
            }
            else cout << -1 line;
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