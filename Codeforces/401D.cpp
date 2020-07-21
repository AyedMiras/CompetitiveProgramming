#include <bits/stdc++.h>
using namespace std;
const int N = 15,M=100;
long long int res,dp[1<<N][N][M];
int n,m;
string s;

int setBits(int i) {
    if (!i) return 0;
    return (i&1) + setBits(i>>1);
}

long long int poww(long long int a,long long int b) {
    if (!b) return 1LL;
    return a * pow(a,b-1);
}

long long int solve() {
    for (int i=0;i<n;i++) dp[1<<i][i][s[i]-'0'] =1;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if (i&(1<<j)) {
                for (int k=0;k<n;k++) {
                    if (i&(1<<k) && k!=j) {
                        for (int mm=0;mm<m;mm++) {
                            dp[i][j][(mm + (s[j]-'0')*((poww(10,setBits(i)-1)))%m)%m] += dp[i^(1<<j)][k][mm];
                        }
                    }
                }
            }
        }
    }
    for (int j=0;j<n;j++) {
        if (s[j]-'0') res += dp[(1<<n)-1][j][0];
    }
    return res;
}

int main() {
    cin >> s >> m;
    n=s.length();
    cout << solve() << endl;
}
