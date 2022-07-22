/**
 * author: theKicker
 * date: 2022-01-13 18:30:42 
**/
#include <bits/stdc++.h>
using namespace std;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define pp pop_back
#define si set<int>
#define mii map<int, int>

int main(){
    int t;
    in t;
    while (t--) {
        int n;
        in n;
        vi arr;
        si reqd;        // to store numbers from 1 to n
        for (int i = 0; i < n; i++) {
            int tmp;
            in tmp;
            arr.pb(tmp);
            reqd.insert(i + 1);
        }
        vi::iterator itr1 = arr.begin();
        for (itr1; itr1 != arr.end(); itr1++) {
            si::iterator i = reqd.find(*itr1);
            if (i != reqd.end()) {        // if ith elem of arr is in the reqd set
                reqd.erase(i);            // remove it from reqd set now
                *itr1 = -1;               // remove it from the input arr too
            }
        }
        sort(arr.begin(), arr.end());     // sort the input arr
        // sort so that we can extract the smaller required number from the smaller
        // elem of input arr and preserve bigger number to extract bigger reqd num.
        vi::iterator i = arr.begin();
        for (i; i != arr.end(); i++) {
            int num = *i;
            if (num == -1) continue;
            while (num > 1) {           // divide by 2
                num /= 2;
                si::iterator itr = reqd.find(num);
                if (itr != reqd.end()) {    // if, after div by 2, it exists in reqd set
                    reqd.erase(itr);    // remove it from reqd set
                    break;
                }
            }
        }
        string ans = (reqd.size() == 0) ? "YES\n" : "NO\n";
        // if all elem of reqd is removed this means we can make the permutation
        out ans;
    }
}