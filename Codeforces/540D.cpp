#include <bits/stdc++.h>
using namespace std;
const int N=110;
int r,s,p;
double dp[N][N][N];

bool over(int i, int j, int k) {
    int cnt=0;
    cnt+=(!i)+(!j)+(!k);
    return cnt>=2;
}

int main() {
    cin >> r >> s >> p;
    dp[r][s][p]=1;
    for(int i=r;i>=0;i--) {
        for(int j=s;j>=0;j--) {
            for(int k=p;k>=0;k--) {
                if(!i && !j && !k)
                    continue;
                dp[i][j][k]+=(dp[i+1][j][k]*(i+1)*k+dp[i][j+1][k]*(j+1)*i+dp[i][j][k+1]*(k+1)*j)/((i+j+k)*(i+j+k+1)/2);
                if(!over(i,j,k))
                    dp[i][j][k]/=(1.0-(double)(i*(i-1)+j*(j-1)+k*(k-1))/((i+j+k)*(i+j+k-1)));
            }
        }
    }
    double res1=0,res2=0,res3=0;
    for(int i=1;i<=max(max(r,s),p);i++) {
        res1+=dp[i][0][0];
        res2+=dp[0][i][0];
        res3+=dp[0][0][i];
    }
    cout << setprecision(12) << res1 << " " << res2 << " " << res3 << endl;
}
