// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

class Box {
    public:
        int l, b, h;
        Box(int x, int y, int z) {
            l = x;
            b = y;
            h = z;
        }
        void volume() {
            cout << "Volume: " << l * b * h << endl;
        }
};

int main() {
    Box b(1, 2, 3);
    b.volume();
}