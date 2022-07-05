#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t, l1, l2, l3;
    int sides[3];
    cin >> t;
    while(t--){
        cin >> l1 >> l2 >> l3;
        sides[0] = l1;
        sides[1] = l2;
        sides[2] = l3;
        sort(sides, sides+3);
        int perimeter = l1 + l2 + l3;
 
        if(perimeter % 2 != 0){
            cout << "NO\n";
        }
        else{
            if(sides[0] == sides[1] && sides[2] % 2 == 0){
                cout << "YES\n";
            }
            else if(sides[1] == sides[2] && sides[0] % 2 == 0){
                cout << "YES\n";
            }
            else if((sides[1] - sides[0]) == sides[2]){
                cout << "YES\n";
            }
            else if((sides[2] - sides[0]) == sides[1]){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}