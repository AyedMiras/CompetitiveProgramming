#include <bits/stdc++.h>
using namespace std;
const double INF = (double)(1LL<<50);
int T,n,m,p;
int op[15];
double diff[15];
double graph[55][55];
double apsp[55][55];
double dp[15][1<<15];

int main(){
    cin >> T;
    while(T--) {
        cin >> n >> m;
        n++;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                graph[i][j] = INF;
            }
            graph[i][i]=0;
        }
        for (int i=0;i<m;i++) {
            int u,v;
            double d;
            cin >> u >> v >> d;
            graph[u][v]=graph[v][u]=d;
        }
        cin >> p;
        op[0]=0;diff[0]=0;
        for (int i=1;i<=p;i++) {
            cin >> op[i] >> diff[i];
        }
        p++;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                apsp[i][j]=graph[i][j];
            }
        }

        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    apsp[i][j]=min(apsp[i][j],apsp[i][k]+apsp[k][j]);
                }
            }
        }
        /*
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cout << apsp[i][j]<< " \n"[j==n-1];
        cout << endl;
        */
        for (int i=0;i<(1<<p);i++) {
            for (int j=0;j<p;j++) {
                if ((1<<j)&i) {
                    for (int k=0;k<p;k++) {
                        if (i&(1<<k) && k!=j) {
                            dp[j][i] = max(dp[j][i], dp[k][i^(1<<j)] - apsp[op[k]][op[j]] + diff[j]);
                        }
                    }
                }
            }
        }
        double m=0;
        for (int i=0;i<(1<<p);i++)
            for (int j=0;j<p;j++)
                m = max(m,dp[j][i] - apsp[0][op[j]]);

        cout << m << endl;
    }
}
