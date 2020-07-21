#include <bits/stdc++.h>
using namespace std;
const int K = 10010;
int n,m,xc,yc,k,dx[K],dy[K];
long long int cnt;

int main() {
    cin >> n >> m >> xc >> yc >> k;
    xc--,yc--;
    for (int i=0;i<k;i++) cin >> dx[i] >> dy[i];
    for (int i=0;i<k;i++) {
        int p,xx=-1,yy=-1;
        if (dx[i]>0) xx = (n-1-xc)/dx[i];
        if (dx[i]<0) xx = -xc/dx[i];
        if (dy[i]>0) yy = (m-1-yc)/dy[i];
        if (dy[i]<0) yy = -yc/dy[i];
        if (xx==-1) p =yy;
        else if (yy==-1) p=xx;
        else p = min(xx,yy);
        xc+= p*dx[i];
        yc+= p*dy[i];
        cnt+=p;
    }
    cout << cnt << endl;
}
