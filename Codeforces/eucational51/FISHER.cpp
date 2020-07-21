#include <bits/stdc++.h>
#define ii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int N=55;
const int T=1010;
int n,t,t1me[N][N],toll[N][N];
ii d[N][T];

ii solve(int i,int j) {
    if (j<0)
        return make_pair(-1,-1);
    if (i==n-1)
        return make_pair(0,0);
    if (d[i][j].first!=-1)
        return d[i][j];
    ii m1n=make_pair(INF,INF);
    for (int k=0;k<n;k++) {
        if (i==k) continue;
        ii path = solve(k,j-t1me[i][k]);
        if (path.first+toll[i][k] < m1n.first && path.second!=-1)
            m1n.first=path.first+toll[i][k],m1n.second=path.second+t1me[i][k];
    }
    return d[i][j]=m1n;
}

int main() {
    while(1) {
        memset(d,-1,sizeof(d));
        cin >> n >> t;
        if (!n && !t)
            return 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> t1me[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> toll[i][j];
        ii res = solve(0,t);
        cout << res.first << " " << res.second << endl;
    }
}
