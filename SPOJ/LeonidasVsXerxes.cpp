#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int N = 100100;
typedef struct {
    int ans;
    int prx;
    int sufx;
} node;

int T,n,q,ll[N],rr[N];
node st[4*N];
lli p[N];

node comb(node a, node b, int ss, int se, int mid) {
    node res;
    res.ans = max(p[mid+1]>p[mid]?a.sufx+b.prx:0, max(a.ans,b.ans));
    res.prx = (p[mid+1]>p[mid] && a.ans == (mid-ss+1))?(mid-ss+1)+b.prx:a.prx;
    res.sufx= (p[mid+1]>p[mid] && b.ans == (se-mid))?(se-mid)+a.sufx:b.sufx;
    return res;
}

void build(int si, int ss, int se) {
    if (ss==se) {
        st[si].ans = st[si].prx = st[si].sufx = 1;
        return;
    }
    int mid = ss + (se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = comb(st[2*si+1],st[2*si+2],ss,se,mid);
}

void update(int si, int ss, int se, int x, lli val) {
    if (ss>x ||se <x) return;
    if (ss==se) {
        p[x]+=val;
        return;
    }
    int mid = ss + (se-ss)/2;
    update(2*si+1,ss,mid,x,val);
    update(2*si+2,mid+1,se,x,val);
    st[si] = comb(st[2*si+1],st[2*si+2],ss,se,mid);

}

node query(int si, int ss, int se, int qs, int qe) {
    if (ss>qe || se <qs) {
        node n;n.ans=n.prx=n.sufx=0;
        return n;
    }
    if (ss>=qs && se <=qe) return st[si];
    int mid = ss+ (se-ss)/2;
    node l = query(2*si+1,ss,mid,qs,qe);
    node r = query(2*si+2,mid+1,se,qs,qe);
    return comb(l,r,ss,se,mid);
}

void print(int si, int ss, int se) {
    cout << st[si].ans << " " << ss << " " << se << endl;
    if(ss==se) return;
    int mid = ss+ (se-ss)/2;
    print(2*si+1,ss,mid);
    print(2*si+2,mid+1,se);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> n >> q;
        for (int i=0;i<n;i++) cin >> p[i];
        build(0,0,n-1);
        for (int i=0;i<q;i++) {
            bool flag;
            lli x,y;
            cin >> flag >> x >> y;
            if (flag) update(0,0,n-1,--x,y);//print(0,0,n-1);
            else cout << query(0,0,n-1,--x,--y).ans << endl;
        }
    }
}
