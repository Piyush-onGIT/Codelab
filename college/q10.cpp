#include<iostream>
using namespace std;
class box
{
    public:
    int val;

    box operator ++()
    {
        box o;
        o.val = ++val;
        return o;   
    }
    void print()
    {
        cout<<"value :"<< val << endl;
    }

};
int main()
{
    box o1,o2;
    o1.val=5;
    o1.print();
    o1 = ++o1;
    o1.print();
}