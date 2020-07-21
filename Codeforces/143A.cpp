#include <bits/stdc++.h>
using namespace std;
int r1,r2,c1,c2,d1,d2,x1,x2,y1,y2;
set<int> s;

bool isDigit(int a) {
    return (a>0 && a<=9);
}

int main() {
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    x1 = (r1+c1-d2);
    y1 = (c2+r1-d1);
    x2 = (r2+c1-d1);
    y2 = (c2+r2-d2);
    s.insert(x1);
    s.insert(y1);
    s.insert(x2);
    s.insert(y2);
    if (x1&1 || x2&1 || y2&1 || y1&1 || s.size()!=4 || !isDigit(x1/2) || !isDigit(x2/2) || !isDigit(y1/2) || !isDigit(y2/2))
        cout << -1 << endl;
    else
        cout << x1/2 << " " << y1/2 << endl << x2/2 << " " << y2/2 << endl;

}
