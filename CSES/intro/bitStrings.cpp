/**
 * @author: kicker
 * @date: 02:20, 07 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
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


ll pw(ll base, ll power, ll m) {
    if (power == 0) return 1 % m;
    if (power % 2 == 0) {
        ll t = pw(base, power / 2, m);
        return (1ll * t * t) % m;
    }
    else {
        ll t = pw(base, (power - 1) / 2, m);
        t = 1ll * t * t;
        return (t * base) % m;
    }
}

void solve() {
	ll n;
	cin >> n;
	cout << pw(2, n, M) line;
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  
   #ifndef ONLINE_JUDGE
   freopen("../../input.txt", "r", stdin);
   freopen("../../error.txt", "w", stderr);
   freopen("../../output.txt", "w", stdout);
   #endif
  
   ll t;
   // cin >> t;
   t = 1;
   while(t--) {
      solve();
   }
  
   cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}