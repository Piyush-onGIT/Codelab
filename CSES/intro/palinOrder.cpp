/**
 * @author: kicker
 * @date: 13:54, 27 April 2022
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
	string str;
	cin >> str;
	ll n = str.size();
	vll cnt(200, 0);
	set<char> c;
	
	loop(i, 0, n) {
		cnt[str[i]]++;
	}

	if (n % 2) {
		ll sum = 0;
		loop(i, 0, n) {
			sum += cnt[str[i]];
		}
		if (floor((sum + 1) / 2) != ceil((sum + 1) / 2)) {
			cout << "NOT POSSIBLE\n";
		}
		else {
			set<char> c;
			loop(i, 0, n) c.insert(str[i]);
			
			string ans = "";
			loop(i, 0, n) {
				if (cnt[str[i]] > 1) {
					string tmp(cnt[str[i]]/2, str[i]);
					ans += tmp;
				}
			}
			cout << ans line;
		}
	}
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  
   #ifndef ONLINE_JUDGE
   freopen("../../input.txt", "r", stdin);
   freopen("../../error.txt", "w", stderr);
   freopen("../../output.txt", "w", stdout);
   #endif
  
   ll t = 1;
   // cin >> t;
   while(t--) {
      solve();
   }
  
   cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}