#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    while(cin>>n && n) {
        int x,y,z,l,m4x[3],m1n[3];
        memset(m4x,0x80,sizeof(m4x));
        memset(m1n,0x3f,sizeof(m1n));
        for (int i=0;i<n;i++) {
            cin >> x >> y >> z >> l;
            m4x[0] = max(m4x[0],x);
            m4x[1] = max(m4x[1],y);
            m4x[2] = max(m4x[2],z);
            m1n[0] = min(m1n[0],x+l);
            m1n[1] = min(m1n[1],y+l);
            m1n[2] = min(m1n[2],z+l);
        }
        cout << max(0,m1n[0]-m4x[0])*max(0,m1n[1]-m4x[1])*max(0,m1n[2]-m4x[2]) << endl;
    }
}
