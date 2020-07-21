#include <bits/stdc++.h>
using namespace std;
long long int r,x1,y1,x2,y2;

int main() {
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    cout << ceil(d/(2*r)) << endl;
}
