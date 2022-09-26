/** author: kicker
*   created: 16-08-2022 21:09
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
    ll n, q;
    cin >> n >> q;
    deque<ll> a;
    ll tmp;
    map<ll, ll> players;
    loop(i, 0, n) {
    	cin >> tmp;
    	players[i + 1] = tmp;
    	a.push_back(tmp);
    }

    // ll mxR = INT_MIN;
    // vector<pair<ll, ll>> que;
    // ll q1, q2;
    // loop(i, 0, q) {
    // 	cin >> q1 >> q2;
    // 	que.pb({q1, q2});
    // }

    ll round = 0;
    vector<vll> state(n + 1);

    while (a.front() != n) {
        ll p1 = a.front();
        a.pop_front();
        ll p2 = a.front();
        a.pop_front();

        if (p1 > p2) {
            loop(i, 1, n + 1) {
                if (i == p1) {
                    if (round == 0) state[i].pb(1);
                    else state[i].pb(state[i][round - 1] + 1);
                }
                else state[i].pb(0);
            }
            a.push_front(p1); a.pb(p2);
        }
        else {
            loop(i, 1, n + 1) {
                if (i == p2) {
                    if (round == 0) state[i].pb(1);
                    else state[i].pb(state[i][round - 1] + 1);
                }
                else state[i].pb(0);
            }
            a.push_front(p2); a.pb(p1);
        }
        round++;
    }

    if (players[1] == n) {
        while (q--) {
            ll p1, r;
            cin >> p1 >> r;
            if (players[p1] == n) cout << r line;
            else cout << 0 line;
        }
        return;
    }
    while (q--) {
        ll p1, r;
        cin >> p1 >> r;
        if (state[players[p1]].size() >= r) cout << state[players[p1]][r - 1] line;
        else {
            if (players[p1] == n) {
                ll win = 0;
                if (state[players[p1]].size() != 0) win += state[players[p1]][state[players[p1]].size() - 1];
                ll rem = r - state[n].size();
                win += rem;
                cout << win line;
            }
            else if (state[players[p1]].size() != 0) cout << state[players[p1]][state[players[p1]].size() - 1] line;
            else cout << 0 line;
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