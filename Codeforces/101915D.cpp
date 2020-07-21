#include <bits/stdc++.h>
using namespace std;
const int P=22;
int n,p,T,m4x,bit[P],dp[1<<P];

int numB(int a){
    int cnt=0;
    for (int i=0;i<p;i++)
        if (1<<i & a)
            cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(bit,0,sizeof(bit));
        memset(dp,0,sizeof(dp));
        m4x=0;
        cin >> p >> n;
        for (int i=0;i<n;i++) {
            int b,g;
            cin >> b >> g;
            bit[--b]^=(1<<--g);
        }
        for (int i=0;i<(1<<p);i++) {
            int flag=0;
            int k=(1<<p)-1;
            for (int j=0;j<p;j++)
                if ((1<<j)&i)
                    k&=bit[j],flag=1;
            dp[i]=(flag?numB(k):0);
        }
        for (int i=0;i<(1<<p);i++)
            m4x=max(m4x,dp[i]+numB(i));
        cout << m4x << endl;
    }
}
