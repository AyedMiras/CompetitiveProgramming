#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,x,l,r,cnt,ind,a[N];

int main() {
    cin >> n >> x;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    l = lower_bound(a,a+n,x) - a;
    r = upper_bound(a,a+n,x) - a;
    if (l<n && a[l]!=x) n++,cnt++;
    else r--;
    if ((n+1)/2>=l+1 && (n+1)/2<=r+1) return 0*printf("%d\n",cnt);
    if ((l+1)>(n+1)/2) ind = l;
    else ind = r;
    ind++;
    //cout << ind << " " << (n+1)/2 << endl;
    while((n+1)/2 != ind) {
        if (ind<(n+1)/2) ind++;
        n++;
        cnt++;
    }
    cout << cnt << endl;
}
