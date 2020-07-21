#include <bits/stdc++.h>
using namespace std;
int n,m,K;
long long int p[5005],cum[5005];
long long int dp[5005][5005];

int main() {
    ios::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n >> m >> K;
    for (int i=1;i<=n;i++) cin >> p[i];
    if (m==1) {
        sort(p+1,p+n+1);
        long long int s=0;
        for (int i=n-K+1;i<=n;i++) s+=p[i];
        cout << s << endl;
        return 0;
    }
    for (int i=1;i<=n;i++) cum[i] = p[i] + cum[i-1];
    for (int i=m;i<=n;i++) dp[1][i]=cum[i]-cum[i-m];
    for (int i=2;i<=K;i++) {
        for (int j=i*m;j<=n-(K-i)*m;j++) {
            for (int k=m*(i-1);k<=j-m;k++ )
                dp[i][j] = max(dp[i][j],dp[i-1][k]+cum[j]-cum[j-m]);
        }
    }
    long long int res=0;
    for(int i=K*m;i<=n;i++) res = max(res,dp[K][i]);
    cout << res << endl;

}
