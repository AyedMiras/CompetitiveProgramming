#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int n,m,a[1<<N],p,b,st[4*(1<<N)];

int build(int si,int ss, int se) {
    if (ss==se) {
        st[si]=a[ss];
        return 0;
    }
    int mid = ss + (se-ss)/2;
    int flag = build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = flag?st[2*si+1]^st[2*si+2]:st[2*si+1]|st[2*si+2];
    return 1 - flag;
}

int update(int si, int ss,int se, int ind, int val) {
    if (ss>ind || se <ind) return -1;
    if (ss==se) {
        a[ind]=val;
        st[si]=val;
        return 0;
    }
    int mid = ss + (se-ss)/2;
    int flag1 = update(2*si+1,ss,mid,ind,val);
    int flag2 = update(2*si+2,mid+1,se,ind,val);
    if (flag1!=-1) {
        st[si] = flag1?st[2*si+1]^st[2*si+2]:st[2*si+1]|st[2*si+2];
        return 1-flag1;
    }
    st[si] = flag2?st[2*si+1]^st[2*si+2]:st[2*si+1]|st[2*si+2];
    return 1-flag2;
}

int main() {
    cin >> n >> m;
    for (int i=0;i<(1<<n);i++) cin >> a[i];
    build(0,0,(1<<n)-1);
    //cout << st[0] << " " << st[1] << " " << st[2];
    for (int i=0;i<m;i++) {
        cin >> p >> b;
        update(0,0,(1<<n)-1,--p,b);
        cout << st[0] << endl;
    }
}
