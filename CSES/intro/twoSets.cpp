/**
 * @author: kicker
 * @date: 02:02, 07 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
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

void solve() {
	ll n;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	if (sum % 2) cout << "NO\n";
	else {
		ll half = sum / 2;
		set<ll> first, second;
		ll arr[n];
		for (ll i = 1; i <= n; i++) arr[i - 1] = i;
		
		ll tmp = half;
		for (ll i = n - 1; i >= 0; i--) {
			if (arr[i] <= tmp) {
				first.insert(arr[i]);
				tmp -= arr[i];
			}
			else second.insert(arr[i]);
		}
		cout << "YES\n";
		cout << first.size() line;
		for (auto i = first.begin(); i != first.end(); i++) cout << *i << " ";
		cout line;
		cout << second.size() line;
		for (auto i = second.begin(); i != second.end(); i++) cout << *i << " ";
		cout line;
	}
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