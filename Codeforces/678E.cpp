#include <bits/stdc++.h>
using namespace std;
int n;
double p[20][20];
double dp[20][1<<20];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> p[i][j];
    for (int i=0;i<n;i++)
        dp[i][1<<i] = 1;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            double s=0;
            bool flag=false;
            if (i&(1<<j)) {
                for (int k=0;k<n;k++) {
                    if (i&(1<<k) && k!=j) {
                        s+=dp[k][i^(1<<j)]*p[j][k];
                        flag = 1;
                        //dp[j][i] = dp[k][i^(1<<j)]*p[j][k];
                    }
                }
            }
            if (flag) dp[j][i] = max(dp[j][i],s);
        }
    }
    printf("%.6f",dp[0][(1<<n)-1]);
}
