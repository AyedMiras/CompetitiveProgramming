#include <bits/stdc++.h>
using namespace std;
const int N=5005;
string s;
int n,cnt,dp[N][N],ugly[N][N];

int pretty(int l, int r) {
    if (dp[l][r]!=-1)
        return dp[l][r];
    if (l>=r)
        return 0;
    if ((r-l+1) &1)
        return dp[l][r]=0;
    //cout << l << " " << r << endl;
    if (s[l]!=')' && s[r]!= '(' && (l+1 ==r || pretty(l+1,r-1)) )
        return dp[l][r]=1;
    for (int k=1;k<r-l;k+=2) {
        if (pretty(l,l+k) && pretty(l+k+1,r))
            return dp[l][r]=1;
    }
    return dp[l][r]=0;
}

int main() {
    cin >> s;
    n = s.size();
    memset(dp,-1,sizeof(dp));
    pretty(0,n-1);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j+=2) {
            //cout << i << " " << j << " " << pretty(i,j) << endl;
            if (pretty(i,j)==1)
                cnt++;
        }
    cout << cnt << endl;
}
