#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int w,b;
double dp[2][2][N][N];

int main() {
    cin >> w >> b;
    dp[1][0][w][b]=(double)w/(w+b);
    dp[1][1][w][b]=(double)b/(w+b);
    for(int i=w;i>=0;i--) {
        for(int j=b;j>=0;j--) {
            if(i==w && j==b)
                continue;
            dp[0][0][i][j]=dp[1][1][i][j+1]*i/(i+j);
            dp[0][1][i][j]=dp[1][1][i][j+1]*j/(i+j);
            dp[1][0][i][j]=dp[0][1][i][j+2]*((double)(j+1)/(i+j+1))*((double)i/(i+j))+dp[0][1][i+1][j+1]*((double)(i+1)/(i+j+1))*((double)i/(i+j));
            dp[1][1][i][j]=dp[0][1][i][j+2]*((double)(j+1)/(i+j+1))*((double)j/(i+j))+dp[0][1][i+1][j+1]*((double)(i+1)/(i+j+1))*((double)j/(i+j));
        }
    }
    double res=0;
    for(int i=1;i<=w;i++)
        for(int j=0;j<=b;j++)
            res+=dp[1][0][i][j];
    cout << setprecision(12) << res << endl;
}
