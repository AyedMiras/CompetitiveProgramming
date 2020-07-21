#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=500500;
int n;
ll a[N],cnt;
map<ll,int> m;

void _dec(ll x) {
    m[x]--;
    if (!m[x])
        m.erase(m.find(x));
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i],m[a[i]]++;
    if (n==1)
        return 0*printf("%d\n",a[0]);
    cnt=n;
    while(cnt!=1) {
        for (map<ll,int>::iterator it=m.begin();it!=m.end();++it)
            cout << it->first << " " << it->second << "| ";
        cout << endl;
        ll m1=m.begin()->first;
        _dec(m.begin()->first);
        ll m2;
        if (m.begin()->first!=m1)
            m2=m.begin()->first,_dec(m.begin()->first);
        else
            m2=(++m.begin())->first,_dec((++m.begin())->first);
        cout << m1 << " " << m2 << endl;
        m[m2-m1]++;
        cnt--;
    }
    cout << m.begin()->first << endl;
}
