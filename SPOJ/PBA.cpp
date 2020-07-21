#include <bits/stdc++.h>
using namespace std;
const int R = 10;
const int C = 44;
const int MOD = (int)1e9+7;
int T,r,c,dp[R][C];

bool isInside(int i, int j) {
    return (i>=0 && j>=0 && i<r && j<c);
}

int solve() {
    for (int i=0;i<r;i++) dp[i][1] = 1;
    for (int j=2;j<c;j++) {
        for (int i=0;i<r;i++) {
            for (int k=0;k<4;k++) {
                if (isInside(i+dx[k],j+dy[k]))
                    dp[i][j]+=dp[i-1][j+dy[j]];
            }
        }
    }
}

int main() {
    cin >> T;
    while(T--) {
        memset(dp,0,sizeof(dp));
        cin >> r >> c;
        cout << solve() << endl;
    }
}
