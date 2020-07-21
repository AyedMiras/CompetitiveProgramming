#include <bits/stdc++.h>
using namespace std;
const int N=2020;
int n;
long long int m4x,v[N],dp[N][N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> v[i];
    dp[1][1]=v[0];
    dp[1][0]=v[n-1];
    for (int i=2;i<=n;i++)
        for (int j=0;j<=i;j++)
            dp[i][j]=max( (j?dp[i-1][j-1]+v[j-1]*i:0),dp[i-1][j]+v[n-i+j]*i);
    for (int j=0;j<=n;j++)
        m4x = max(m4x,dp[n][j]);
    cout << m4x << endl;
}
