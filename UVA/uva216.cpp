#include <bits/stdc++.h>
using namespace std;
int n,t,parent[10][1<<10];
pair<int,int> co[10];
double dist[10][10],dp[10][1<<10];

double sqr( double x) {
    return x*x;
}
int tsp() {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            dist[i][j] = sqrt( sqr(co[i].first - co[j].first) + sqr(co[i].second - co[j].second) );
        }
    }
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            dp[j][i] = 1e5;
        }
    }
    memset(parent,-1,sizeof(parent));
    for (int i=0;i<n;i++)
        dp[i][1<<i] = 0;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if (i&(1<<j)) {
                for (int k=0;k<n;k++) {
                    if (i&(1<<k) && k!=j) {
                        if (dp[k][i^(1<<j)] + dist[k][j] < dp[j][i])
                            dp[j][i] = dp[k][i^(1<<j)] + dist[k][j], parent[j][i]=k;
                    }
                }
            }
        }
    }
    double m = dp[0][(1<<n)-1];
    int ind = 0;
    for (int i=0;i<n;i++) {
         //cout << dp[i][(1<<n)-1] << " \n"[i==n-1];
         if (m > dp[i][(1<<n)-1])
            m = dp[i][(1<<n)-1],ind = i;
    }
    return ind;

}

int main() {
    //freopen("a.txt","w",stdout);
    cout.precision(2);
    while(1) {
        t++;
        cin >> n;
        if (!n) return 0;
        for (int k=0;k<n;k++) {
            int i,j;
            cin >> i >> j;
            co[k]=make_pair(i,j);
        }
        int ii = tsp();
        int ind = ii;
        int bitmask = (1<<n)-1;
        cout << "**********************************************************" <<endl;
        cout << "Network #" << t << endl;
        while(parent[ind][bitmask] != -1) {
            cout << "Cable requirement to connect (" << co[ind].first << "," << co[ind].second << ") to ("
                << co[parent[ind][bitmask]].first << "," << co[parent[ind][bitmask]].second << ") is "
                << fixed << dist[ind][parent[ind][bitmask]] + 16 << " feet." << endl;
            int aux = ind;
            ind  = parent[ind][bitmask];
            bitmask = bitmask^(1<<aux);
        }
        cout << "Number of feet of cable required is " << fixed << dp[ii][(1<<n)-1] + 16*(n-1) <<"." << endl;
        //cout << "**********************************************************" <<endl;
    }
}
