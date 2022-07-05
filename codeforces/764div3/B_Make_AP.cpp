#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>

int main(){
    int t;
    in t;
    while (t--) {
        int a, b ,c;
        in a >> b >> c;
        // let a and b are in ap
        int diff = b - a;
        int nc = b + diff;      // new c should be this
        if (nc % c == 0 && nc > 0) {
            // if new c is div by given c
            // new c should be positve as m > 0
            outLn("YES");
        }
        else {
            // else let b and c are in ap
            diff = c - b;
            int na = b - diff;      // new a
            if(na % a == 0 && na > 0) {
                // new a should be div by given a
                // new a should be > 0 as m > 0
                outLn("YES");
            }
            else {
                // let c and a are in ap
                diff = c - a;       // this is 2*common diff
                if(diff % 2 != 0) {
                    // diff must be even now as it is 2d
                    outLn("NO");
                }
                else{
                    diff /= 2;
                    // diff = 2d, so divide it by 2
                    int nb = a + diff;
                    if(nb % b== 0 && nb > 0) {
                    // new b should be div by given v
                    // new b should be > 0 as m > 0
                        outLn("YES");
                    }
                    else {
                        outLn("NO");
                    }
                }
            }
        }
    }
}