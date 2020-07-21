#include <bits/stdc++.h>
using namespace std;
long long int dp[2][10][110];
int n;

int main() {
    n = 100;
    for (int i=0;i<10;i++) dp[0][i][1]=dp[1][i][1]=1;
    for (int i=2;i<=n;i++)
        for (int k=0;k<=9;k++)
            for (int j=k;j<=9;j++)
                dp[0][k][i]+=dp[0][j][i-1];

    for (int i=2;i<=n;i++)
        for (int k=9;k>=0;k--)
            for (int j=k;j>=0;j--)
                dp[1][k][i]+=dp[1][j][i-1];

    long long int res=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=9;j++)
            res+= dp[0][j][i]+dp[1][j][i];
    cout << res - 9*n<< endl;
}
