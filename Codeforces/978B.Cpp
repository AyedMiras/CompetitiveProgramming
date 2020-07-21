#include <bits/stdc++.h>
using namespace std;

int x,y;

int main() {
    cin >> x >> y;
    if (fabs(y*log(x) - x*log(y)) < 1e-9) cout << '=' << endl;
    else if (y*log(x) > x*log(y)) cout << '>' << endl;
    else cout << '<' << endl;
}
