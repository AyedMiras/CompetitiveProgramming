#include <bits/stdc++.h>
#define lll long long int
using namespace std;
const int N=550;
const int MOD=998244353;
int n;
lll a[N];
map<lll,lll> m;
vector<lll> f,fac;

lll gcd(lll x,lll y){
    return !y?x:gcd(y,x%y);
}

void factor(lll g){
    for (int i=2;i*i<=g;i++){
        if (g%i==0) {
            fac.push_back(i);
            if (i*i!=g)
                fac.push_back(g/i);
        }
    }
    for (int i=0;i<fac.size();i++)
        m[fac[i]]+=f.size();
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++){
        if (sqrt(a[i])*sqrt(a[i]) == a[i]) {
            lll sqr = (lll) sqrt(a[i]);
            if (sqrt(sqr)*sqrt(sqr) == sqr) {
                lll sqsq = (lll) sqrt(sqr);
                m[sqsq]++,m[sqsq*sqsq*sqsq]++;
            }
            m[sqr]+=2;
        }
        else if (cbrt(a[i])*cbrt(a[i])*cbrt(a[i])== a[i])
                m[(lll)cbrt(a[i])]+=3;
        else {
            f.push_back(a[i]);
        }
    }
    lll res = 1;
    if (f.size()>1) {
        lll g;
        g = gcd(f[0],f[1]);
        for (int i=2;i<f.size();i++)
            g = gcd(g,f[i]);
        if (g!=1) {
            factor(g);
            for (int i=0;i<f.size();i++)
                m[f[i]/g]++;
        }
    }
    else {
        res *=4;
    }
    for (map<lll,lll>::iterator it = m.begin();it!=m.end();++it)
        res *=1+it->second,res%=MOD;
    cout << res << endl;

}
