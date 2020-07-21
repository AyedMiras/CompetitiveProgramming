#include <bits/stdc++.h>
using namespace std;
const int N=16;
int n,h[N],dp[N][1<<N],perm[N][1<<N];

void init() {
    memset(dp,0,sizeof(dp));
    memset(perm,0,sizeof(perm));
}

int main() {
    ios::sync_with_stdio(0);
    while(1) {
        cin >> n;
        if (!n) return 0;
        init();
        for (int i=0;i<n;i++) {
            cin >> h[i];
        }
        for (int i=0;i<n;i++) dp[i][1<<i] = 2*(h[i]+1),perm[i][1<<i] = 1;
        for (int i=0;i<(1<<n);i++) {
            for (int j=0;j<n;j++) {
                if ((1<<j)&i) {
                    for (int k=0;k<n;k++) {
                        int area = dp[k][i^(1<<j)]-h[k]+2+h[j]+ fabs(h[k]-h[j]);
                        if ((1<<k)&i && k!=j && dp[j][i] <= area) {
                            if (dp[j][i]==area) perm[j][i]+=perm[k][i^(1<<j)];
                            else perm[j][i]=perm[k][i^(1<<j)];
                            dp[j][i] = area;
                            //perm[j][i]= perm[k][i^(1<<j)];
                        }

                    }
                }
            }
        }
        int ind = 0;
        for (int i=0;i<n;i++) {
            if (dp[i][(1<<n)-1] > dp[ind][(1<<n)-1]) ind = i;
        }
        int cnt =0;
        for (int i=0;i<n;i++) {
            if (dp[i][(1<<n)-1]== dp[ind][(1<<n)-1]) cnt+=perm[i][(1<<n)-1];
        }
        cout << dp[ind][(1<<n)-1] << " " << cnt<< endl;
    }
}
