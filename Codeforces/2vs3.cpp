#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,q,st[4*N],mpow[N];
string s;

void build(int si, int ss, int se) {
    if (ss == se) {
        st[si]=s[ss]-'0';
        return;
    }
    int mid = ss + (se -ss) /2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = (st[2*si+1]*mpow[se-mid] + st[2*si+2])%3;
}

void update(int si, int ss, int se, int i) {
    if (ss==se) {
        s[i]= '1';
        st[si] = 1;
        return ;
    }
    //if (ss > i || se < i) return ;
    int mid = ss + (se-ss)/2;
    if (ss<=i && i<=mid)
        update(2*si+1,ss,mid,i);
    else
        update(2*si+2,mid+1,se,i);
    st[si] = (st[2*si+1]*mpow[se-mid] + st[2*si+2])%3;
}


int query(int si, int ss,int se,int qs,int qe) {
    if (ss>qe || se <qs) return 0;
    if (ss>=qs && se<=qe) return (st[si]*mpow[qe-se])%3;
    int mid = ss + (se-ss)/2;
    int l = query(2*si+1,ss,mid,qs,qe);
    int r = query(2*si+2,mid+1,se,qs,qe);
    return (l+r)%3;
    //return (query(2*si+1,ss,mid,qs,qe)*mpow[se-mid] + query(2*si+2,mid+1,se,qs,qe) )%3;
}

void print(int i, int l, int r) {
    //if (l>r) return;
    //if (l==0 && r ==4) cout << st[2*i+1] << " " << st[2*i+2] << " " << (1<<(r-(l+r)/2)) << " ";
    cout << st[i] << " " << l << " " << r << endl;
    if (l==r) return;
    int mid = l+ (r-l)/2;
    print (2*i+1,l,mid);
    print(2*i+2,mid+1,r);
}
int main() {
    cin >> n >> s >> q;
    mpow[0]=1;
    for (int i=1;i<=n;i++) {
        mpow[i] = (mpow[i-1]*2)%3;
    }
    build(0,0,n-1);
    //print(0,0,n-1);
    for (int i=0;i<q;i++) {
        int flag,l,r;
        cin >> flag;
        if (!flag) {
            cin >> l >> r;
            cout << query(0,0,n-1,l,r) << endl;
        }
        else {
            cin >> l;
            if (s[l]=='0')
                update(0,0,n-1,l);
        }
        //if (i==4) cout << s << " ", print(0,0,n-1);
    }
}
