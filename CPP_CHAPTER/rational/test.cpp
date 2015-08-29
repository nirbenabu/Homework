#include<iostream>
#include "rational.hpp"

using namespace std;

int main()
{

    Rational r(1,2), r2(2.5); // 1/2, 5/2
    r2.printf(); // 5/2
    (2+r).print(); // 2.5
    cout<<endl;
    float n = r+2;
    cout<<n<<endl; // 2.5
    (r-r2).print(); // -2
    cout<<endl;
    (r*2).print(); // 1
    cout<<endl;
    cout<<r*2<<endl; // 1
    n = r*2;
    (r/r2).print(); // 1/5
    cout<<endl;
    cout<<n<<endl; // 1

    return 0;
}
