#include <bits/stdc++.h>
using namespace std;
int n,x,y,d,m;

int main() {
    cin >> n >> d >> m;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        if (x+y-d>=0 && x+y-2*n+d<=0 && -x+y-d<=0 && -x+y+d>=0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
