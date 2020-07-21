#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,y,g;

void euc(int a, int b) {
    if (!b) {x = 1; y = 0; g = a; return;}
    euc(b, a%b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {
    cin >> a >> b >> c;
    euc(a,b);
    if (c%g) { cout << "No" << endl; return 0;}
    x = x*(c/g), y= y*(c/g);
    //cout << ceil(y*g*(-1.0/a)) << " " << floor(x*g*(1.0/b)) << endl;
    if (ceil(y*g*(-1.0/a)) <= floor(x*g*(1.0/b))) cout << "Yes" << endl;
    else cout << "No" << endl;
}
