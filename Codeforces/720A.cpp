#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,k,distq1[N],distq2[N],stm1[N],stm2[N];
bool flag;

int abs(int a) {
    return a>=0?a:-a;
}

int main() {
    cin >> n >> m >> k;
    for (int i=0;i<k;i++)
        cin >> stm1[i];
    for (int i=0;i<n*m-k;i++)
        cin >> stm2[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            distq1[i+n*j]=distq2[i+n*j]=i+j+2;
    sort(stm2,stm2+k);
    sort(distq1,distq1+n*m);
    sort(distq2,distq2+n*m);
    for (int i=0;i<k;i++) {
        if (stm1[i]>=distq1[i]) continue;
        flag=1;
        break;
    }
    for (int i=0;i<n*m-k;i++) {
        if (stm2[i]>=distq2[i]) continue;
        flag=1;
        break;
    }
    cout << (!flag?"YES":"NO") << endl;

}
