#include <bits/stdc++.h>
using namespace std;
struct query {
    int L,R,ind;
};
const int N=30300;
const int M=200200;
const int A=1000100;
int n,m,block,a[N],BIT[A],res[M];
query q[M];
map<int,int> m4p;

int get(int i){
    int s=0;
    for(;i>0;i-=i&-i)
        s+=BIT[i];
    return s;
}

void update(int i, int v){
    for(;i<=A;i+=i&-i)
        BIT[i]+=v;
}

void up(int i) {
    if (!m4p[a[i]])
        update(a[i],1);
    m4p[a[i]]++;
}

void down(int i){
    m4p[a[i]]--;
    if (!m4p[a[i]])
        update(a[i],-1);
}

bool comp(query q1,query q2){
    if(q1.L/block != q2.L/block)
        return q1.L/block < q2.L/block;
    return q1.R<q2.R;
}

int main() {
    scanf("%d",&n);
    block = (int) sqrt(n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].ind=i;
        q[i].L--;
        q[i].R--;
    }
    sort(q,q+m,comp);
    int currL=0,currR=0;
    for (int i=0;i<m;i++){
        while(currL<q[i].L)
            down(currL++);
        while(currL>q[i].L)
            up(currL--);
        while(currR<=q[i].R)
            up(currR++);
        while(currR>q[i].R+1)
            down(--currR);
        //cout << q[i].L << " " << q[i].R << " " << s.size() << endl;
        res[q[i].ind]=get(A);
    }
    for (int i=0;i<m;i++)
        printf("%d\n",res[i]);
}
