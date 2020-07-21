#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n;
double a[N][N],dp[1<<N];

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    dp[(1<<n)-1]=1;
    for(int i=(1<<n)-1;i>0;i--) {
        int cnt=0;
        for(int j=0;j<n;j++)
            if ((1<<j)&i)
                cnt++;
        for(int j=0;j<n;j++) {
            if ((1<<j)&i) {
                for(int k=0;k<n;k++) {
                    if(k!=j && (1<<k)&i) {
                        dp[i^(1<<k)]+=2*dp[i]*a[j][k]/(cnt*(cnt-1));
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << setprecision(12) << dp[1<<i] << " \n"[i==n-1];
}
