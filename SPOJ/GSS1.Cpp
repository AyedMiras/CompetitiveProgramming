#include <bits/stdc++.h>
using namespace std;
const int N = 50500;
int n,m,x,y,a[N],st[2*N];

int getSum(int si, int ss, int se, int qs, int qe) {
    if (qs<= ss && qe>=se) return st[si];
    if (se<qs || ss>qe) return 0;
    int mid = ss + (se-ss)/2;
    return getSum(2*si+1,ss,mid,qs,qe) + getSum(2*si+2,mid+1,se,qs,qe);
}
void update(int si, int ss, int se, int i, int newValue) {
    if (i<ss || i>se) return ;
    st[si] = st[si] + newValue - a[i];
    if (ss!=se) {
        int mid = ss + (se-ss)/2;
        update(2*si+1,ss,mid,i,newValue);
        update(2*si+2,mid+1,se,i,newValue);
    }
}
int build(int si, int ss, int se) {
    if (ss==se) {
        st[si] = a[ss];
        return arr[ss];
    }
    int mid = ss + (se - ss)/2;
    st[si] = build(si*2+1, ss, mid) + build(si*2+2, mid+1,se);
    return st[si];
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        cout << query(x,y) << endl;
    }
}
