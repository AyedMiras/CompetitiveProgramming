#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
int n,m,ind;
int st[4*N];
char c;
string inp;

void build(int si, int ss, int se) {
    if (ss==se) {
        st[si]=(inp[ss]=='.'?1:0);
        return;
    }
    int mid = ss + (se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = st[2*si+1] + st[2*si+2] - (inp[mid]==inp[mid+1] && inp[mid]=='.'?1:0);
}

void print(int si, int ss, int se) {
    cout << st[si] << " " << ss << " " << se << endl;
    if (ss==se) return;
    int mid = ss + (se-ss)/2;
    print(2*si+1,ss,mid);
    print(2*si+2,mid+1,se);
}

void update(int si, int ss, int se,int i, char val) {
    if (ss>i || se<i) return;
    if (ss==se) {
        st[si]=(val=='.'?1:0);
        return;
    }
    int mid = ss + (se-ss)/2;
    update(2*si+1,ss,mid,i,val);
    update(2*si+2,mid+1,se,i,val);
    st[si] = st[2*si+1] + st[2*si+2] - (inp[mid]==inp[mid+1]?1:0);
}

int main() {
    cin >> n >> m >> inp;
    build(0,0,n-1);
    print(0,0,n-1);
    cout << st[0] << endl;
    for (int i=0;i<m;i++) {
        cin >> ind >> c;
        update(0,0,n-1,--ind,c);
        cout << st[0] << endl;
    }
}
