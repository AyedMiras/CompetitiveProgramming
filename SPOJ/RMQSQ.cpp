#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,q,a[N],lookup[N][(int)ceil(log(N)/log(2))+1];

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        lookup[i][0]=i;
    for(int j=1;(1<<j)<=n;j++) {
        for(int i=0;i+(1<<j)-1<n;i++) {
            if (a[lookup[i][j-1]]<a[lookup[i+(1<<(j-1))][j-1]])
                lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
        }
    }
    cin >> q;
    for(int i=0;i<q;i++) {
        int l,r,j;
        cin >> l >> r;
        j=(int)(log(r-l+1)/log(2));
        cout << min(a[lookup[l][j]],a[lookup[r-(1<<j)+1][j]]) << endl;
    }
}
