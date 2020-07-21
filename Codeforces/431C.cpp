#include <iostream>
#include <algorithm>
#define lli long long int
#define MOD 1000000007
using namespace std;

lli path[105][2];

int main() {
    int n,k,d;
    cin >> n >> k >> d;
    for (int i=1;i<d;i++)
        path[i][0]=1;
    for (int i=d;i<=k;i++)
        path[i][1]=1;
    for (int i=2;i<=n;i++) {
        lli sum1 = 0,sum2 = 0;
        for (int j=1;j<min(i,d);j++) {
            sum1+= path[i-j][0];
            sum2+= path[i-j][1];
            sum1= sum1%MOD;
            sum2= sum2%MOD;
        }
        path[i][0]+=sum1;
        path[i][0]= path[i][0] % MOD;
        for (int j=d;j<min(i,k+1);j++) {
            sum2+=path[i-j][0]+ path[i-j][1];
            sum2= sum2% MOD;
        }
        path[i][1]+=sum2;
        path[i][1]=path[i][1]%MOD;
    }
    cout << path[n][1] << endl;
    return 0;
}
