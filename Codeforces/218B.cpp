#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],b[N],c[N],m1n,m4x,cnt;

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++)
        cin >> a[i],b[i]=c[i]=a[i];
    sort(b,b+m);
    sort(c,c+m,greater<int>());
    for (int i=0;i<m;i++) {
        if (cnt==n)
            break;
        while(cnt<n && a[i])
            cnt++,m1n+=b[i],b[i]--;
    }
    cnt=0;
    int i=0;
    while(cnt<n && i<m-1) {
        while(cnt<n && c[i]>c[i+1])
            m4x+=c[i],cnt++,c[i]--;
        i++;
    }

}
