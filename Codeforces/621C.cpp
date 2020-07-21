#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
ll n,p,l[N],r[N],d[N];
double s,divComb,numComb=1;

int main() {
    cin >> n >> p;
    for(int i=0;i<n;i++)
        cin >> l[i] >> r[i];
    for(int i=0;i<n;i++)
        numComb*=(r[i]-l[i]+1);
    for(int i=0;i<n;i++) {
        s+=(r[i]/p-l[i]/p+(l[i]%p==0))*(numComb/(r[i]-l[i]+1))*(n-1)*2000;
        d[i]=r[i]/p-l[i]/p+(l[i]%p==0);
        divComb+=(double)d[i]/(r[i]-l[i]+1);
    }
    for(int i=0;i<n;i++) {
        s-= ((double)d[i]/(r[i]-l[i]+1)) * 1000 * numComb * (divComb - (double)d[i]/(r[i]-l[i]+1) );
    }
    cout << s/numComb << endl;
}
