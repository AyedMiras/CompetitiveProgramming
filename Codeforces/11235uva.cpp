#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,q,a[N],st[4*N],l[N],r[N];

void build(int si, int ss, int se) {
    if (se==ss) {
        st[si]=1;return;
    }
    int mid = ss+ (se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    if (a[ss]==a[se]) {st[si] = se-ss+1;return;}
    st[si] = max(st[2*si+1],st[2*si+2]);
    if (a[mid]!=a[mid+1]) return;
    else if (l[mid]>=ss && r[mid]<=se ) st[si] = max(st[si],r[mid] - l[mid] +1);
    else if (l[mid]>=ss) st[si] = max(st[si],se - l[mid]+1);
    else st[si] = max(st[si],r[mid] - ss +1);
}


int query(int si, int ss, int se, int qs, int qe) {
    if (se<qs || ss>qe) return 0;
    if (ss>=qs && se<=qe) return st[si];
    int mid = ss + (se-ss)/2;
    int ll = query(2*si+1,ss,mid,qs,qe);
    int rr = query(2*si+2,mid+1,se,qs,qe);
    //if (a[ss]==a[se]) return se-ss+1;
    if (a[mid]!=a[mid+1]) return max(ll,rr);
    if (l[mid]>=max(ss,qs) && r[mid]<=min(se,qe)) return max(ll,max(rr,r[mid] - l[mid] +1));
    if (l[mid]>=max(ss,qs)) return max(ll,max(rr,min(se,qe) - l[mid]+1));
    else if (r[mid]<=min(se,qe) ) return max(ll,max(rr,r[mid]-max(ss,qs) +1));
    return min(se,qe)-max(ss,qs)+1;
}

/*
int query(int si, int ss, int se, int qs, int qe) {
    if (se<qs || ss>qe) return 0;
    if (ss>=qs && se<=qe) return st[si];
    if (ss==se) {
        if (r[ss]<=qe && l[ss]>=qs) return r[ss]-l[ss]+1;
        if (r[ss]<=qe) return r[ss]-qs+1;
        if (l[ss]>= qs) return qe-l[ss]+1;
        return qe-qs+1;
    }
    int mid = ss + (se-ss)/2;
    return max(query(2*si+1,ss,mid,qs,qe),query(2*si+2,mid+1,se,qs,qe));
}*/

void print(int si, int ss, int se) {
    cout << st[si] <<" "<< ss <<" "<< se << endl;
    if(ss == se) return;
    int mid = ss + (se-ss)/2;
    print(2*si+1,ss,mid);
    print(2*si+2,mid+1,se);
}

int main() {
    ios::sync_with_stdio(0);
    while(1) {
        cin >> n;
        if (!n) return 0;
        cin >> q;
        int ll=0,rr=n-1;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i]!=a[ll]) ll=i;
            l[i]=ll;
        }
        for (int i=n-1;i>=0;i--){
            if (a[i]!=a[rr]) rr=i;
            r[i]=rr;
        }
        build(0,0,n-1);
        //print(0,0,n-1);
        for (int i=0;i<q;i++) {
            cin >> ll >> rr;
            cout << query(0,0,n-1,--ll,--rr) << endl;
        }

    }
}
