/** author: kicker
*   time: 13-06-2022 10:15
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

int ceilingNum(vll arr, int len, ll target) {
    int l = 1, r = len, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid - 1] >= target) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    loop(i, 0, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vll dp(n);
    loop(i, 0, n) {
        dp[i] = (i ? dp[i - 1] : 0) + a[i];
    }

    ll x;
    while (q--) {
    	cin >> x;

        int l = 1, r = n, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(dp[mid - 1] >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans line;
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