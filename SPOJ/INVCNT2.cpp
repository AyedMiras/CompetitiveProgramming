#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
int T,n,a[N],temp[N];
ll BIT[N],invCnt;

void update(int i,int v){
    for(;i<=n;i+=i&-i)
        BIT[i]+=v;
}

ll query(int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[i];
    return sum;
}

int main(){
    cin >> T;
    while(T--){
        memset(BIT,0,sizeof(BIT));
        invCnt=0;
        cin >> n;
        for (int i=0;i<n;i++)
            cin >> a[i],temp[i]=a[i];
        sort(temp,temp+n);
        for (int i=0;i<n;i++)
            a[i]=lower_bound(temp,temp+n,a[i])-temp+1;
        for (int i=n-1;i>=0;i--)
            invCnt+=query(a[i]-1),update(a[i],1);
        cout << invCnt << endl;
    }
}
