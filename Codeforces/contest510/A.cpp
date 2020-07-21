#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,m4x,cnt,a[N];

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++)
        cin >> a[i],m4x=max(m4x,a[i]);
    sort(a,a+n);
    int i=0,j=0,cnt;
    while(i<m && cnt!=n){
        if (!j)
            cnt=0;
        if (a[j]<m4x)
            a[j]++,i++;
        else
            cnt++;
        j=(j+1)%n;
    }
    cout << m4x+ ((m-i)/n)+((m-i)%n?1:0) << " " << m4x+m << endl;
}
