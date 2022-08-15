// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class board {
    public:
        string name;
        int fix, units, p;
        void info() {
            p = 150;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter units: ";
            cin >> units;

            if (units <= 100) {
                p = 50 * units;
            }
            else if (units <= 200) {
                p = 5000;
                units -= 100;
                p += 60 * units;
            }
            else {
                p = 5000;
                units -= 100;
                if (units >= 200) p += 60 * 200;
                units -= 200;
                if (units > 0) p += 80 * units;
            }
            double rup = p / (double) 100;
            if (rup > 250) rup += (15 * rup) / 100;
            cout << "Name: " << name << ", charges: " << rup << endl;
        } 
};

int main() {
    board p;
    p.info();
}