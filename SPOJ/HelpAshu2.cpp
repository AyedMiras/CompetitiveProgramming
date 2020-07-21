#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,q,a[N],BIT[N];

void update(int i,int j){
    for(;i<=n;i+=i&-i)
        BIT[i]+=j;
}

int query(int i){
    int sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i],update(i,a[i]&1);
    cin >> q;
    for (int i=0;i<q;i++){
        int x,y,z;
        cin >> x >> y >> z;
        if (!x) {
            if (a[y]&1 && !(z&1))
                update(y,-1),a[y]--;
            if (!(a[y]&1) && z&1)
                update(y,1),a[y]++;
        }
        if (x==1)
            cout << z-y+1-query(z)+query(y-1) << endl;
        if (x==2)
            cout << query(z)-query(y-1) << endl;
    }
}
