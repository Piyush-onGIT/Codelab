// Name: Piyush Kumar
// Roll: 21116078
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream fout;
    fout.open("input.txt");
    fout << "Hello\n";
    fout << "Hi\n";
    fout.close();

    fstream fout1;
    fstream fin1;
    fin1.open("input.txt");
    fout1.open("output.txt");

    string line;
    while (fin1) {
        getline(fin1, line);
        fout1 << line << endl;
    }
    fout1.close();
}