#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
const int MOD =(int)1e9+7;
int T,n,a[N],sieve[N];
vector <int> fact[N];
map<int,int> ind;


void eras() {
    for (int i=2;i<N;i++) {
        if (!sieve[i]) {
            fact[i].push_back(i);
            for(int j=2;i*j<N;j++)
                sieve[i*j]=1,fact[i*j].push_back(i);
        }
    }
}

long long int modexp(long long int a,long long int b) {
    if (!b) return 1LL;
    long long int res = modexp(a,b/2);
    if (b&1) return (((res*res)%MOD)*a)%MOD;
    else return (res*res)%MOD;
}

int main() {
    cin >> T;
    eras();
    while(T--) {
        ind.clear();
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> a[i];
            for (int j=0;j<fact[a[i]].size();j++) {
                int ii =a[i];
                while(ii%fact[a[i]][j]==0) {
                    ii /= fact[a[i]][j];
                    if (!ind[fact[a[i]][j]]) ind[fact[a[i]][j]] = 1;
                    else ind[fact[a[i]][j]]++;
                }
            }
        }
        long long int res=1LL;
        for (map<int,int>::iterator it = ind.begin();it!=ind.end();++it) {
            if (it->second)
                res*= ((modexp(it->first,it->second+1) -1) * (modexp(it->first - 1,MOD-2)) ) %MOD;
                res%=MOD;
        }
        cout << res << endl;
    }
}
