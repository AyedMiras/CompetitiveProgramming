#include <bits/stdc++.h>
using namespace std;
const int N=10010,K=110;
int n,k,m,a[N],dp[N][K];

int abs(int x) {
    return (x>=0?x:-x);
}

int main() {
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> n >> k;
        for (int j=0;j<n;j++) {
            cin >> a[j];
        }
        memset(dp,0,sizeof(dp));
        dp[0][abs(a[0]%k)]=1;
        for (int j=1;j<n;j++) {
            for (int l=0;l<k;l++) {
                if (dp[j-1][l])
                    dp[j][abs((l+a[j])%k)]=1,dp[j][abs((l-a[j])%k)]=1;
            }
        }
        cout << (dp[n-1][0]?"Divisible":"Not divisible")<< endl;
    }
}
