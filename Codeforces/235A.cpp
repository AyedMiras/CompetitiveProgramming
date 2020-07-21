#include <iostream>
#define ll long long int
using namespace std;
long long int n;


int main() {
    cin >> n;
    if (n==1)
        cout << 1 << endl;
    else if (n==2)
        cout << 2 << endl;
    else
        if (n&1)
            cout << n*(n-2)*(n-1)  << endl;
        else if (n%3)
            cout << (n-3)*(n)*(n-1) << endl;
        else
            cout << (n-2)*(n-1)*(n-3) << endl;
}
