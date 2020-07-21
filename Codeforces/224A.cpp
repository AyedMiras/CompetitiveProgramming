#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int gcd(int x, int y) {
    return (!y?x:gcd(y,x%y));
}
int main() {
    cin >> a >> b >> c;
    cout << gcd(a,b);
    cout << 4*(gcd(a,b)+a/gcd(a,b)+b/(gcd(a,b))) << endl;
}
