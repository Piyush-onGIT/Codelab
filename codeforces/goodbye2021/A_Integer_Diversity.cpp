#include <bits/stdc++.h>
using namespace std;
#define f(j) for(int i = 0; i < j; i++)

int main(){
    int t, n;
    cin >> t;
    while(t--){
        map<int, int> m;
        cin >> n;
        int a;
        int ans = 0;
        f(n){
            cin >> a;
            a = abs(a);
            int lim = (a == 0) ? 1 : 2;
            if(m[a] == lim){
                continue;
            }
            m[a] += 1;
            ans++;
        }
        cout << ans << endl;
    }
}