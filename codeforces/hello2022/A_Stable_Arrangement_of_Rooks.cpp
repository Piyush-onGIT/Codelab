#include <bits/stdc++.h>
using namespace std;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
 
int main(){
    int t;
    in t;
    while(t--){
        int n, k, altPos;
        // all rooks should be placed diagonally in alternate manner
        in n >> k;
            
        altPos = (n+1)/2;   // no. of diagonally alternate pos
        if(k > altPos) outLn(-1);
        else{
            int dot = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j == dot && i == dot && k != 0) {
                        out 'R';
                        dot += 2;
                        k--;
                    }
                    else out '.';
                }
                cout << endl;
            }
        }
    }
}
