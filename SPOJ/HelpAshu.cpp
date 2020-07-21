#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,q,a[N],st[4*N];

void build(int si, int ss, int se) {
    if (ss == se) {
        st[si]=a[ss]&1;
        return;
    }
    int mid = ss+ (se-ss)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si] = st[2*si] + st[2*si+1];
}

void update(int si, int ss, int se, int ind, int diff) {
    if (ss>ind || se <ind) return ;
    if (se == ss) {
        a[ind]+=diff;
        st[si]= a[ind]&1;
        return;
    }
    int mid = ss + (se-ss)/2;
    update(2*si,ss,mid,ind,diff);
    update(2*si+1,mid+1,se,ind,diff);
    st[si] = st[2*si] + st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe) {
    if (ss>qe || se < qs) return 0;
    if (ss>= qs && se <=qe) return st[si];
    int mid = ss +(se-ss)/2;
    return query(2*si,ss,mid,qs,qe) + query(2*si+1,mid+1,se,qs,qe);
}

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    for (int i=0;i<q;i++) {
        int flag,x,y;
        cin >> flag >> x >> y;
        if (!flag) update(1,1,n,x,y-a[x]);
        if (flag==1) cout << (y-x+1) - query(1,1,n,x,y) << endl;
        if (flag ==2) cout << query(1,,n,x,y) << endl;
    }
}
