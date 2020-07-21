#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
int sieve[N],pwr[8];
vector<int> primes;

void init() {
    for (int i=2;i<N;i++)
        if (!sieve[i]) {
            for (int j=2;i*j<N;j++)
                sieve[i*j]=1;
            primes.push_back(i);
        }
    int mul=1;
    for (int i=0;i<8;i++)
        pwr[i]=mul,mul=mul*10;
}

int digCount(int n){
    int cnt=0;
    while(n)
        cnt++,n/=10;
    return cnt;
}

int genBase(int a, int dig, int b){
    int d[8];
    for (int i=0;i<8;i++)
        d[i]=(a/pwr[i])%10;
    for(int i=0;i<dig;i++)
        if ((1<<i)&b)
            a-=pwr[i]*d[i];
    return a;
}

int genFamily(int base, int dig, int mask, int k){
    for(int i=0;i<dig;i++)
        if ((1<<i)&mask)
            base+=pwr[i]*k;
    return base;
}

int main() {
    init();
    for (int i=0;i<primes.size();i++){
        int dig = digCount(primes[i]);
        for (int mask=1;mask<(1<<dig);mask++){
            int cnt=0;
            int res;
            int base = genBase(primes[i],dig,mask);
            for (int k=0;k<=9;k++) {
                if (!k && (mask&(1<<(dig-1)) )) continue;
                if (!sieve[genFamily(base,dig,mask,k)]) {
                    if (!cnt)
                        res=genFamily(base,dig,mask,k);
                    //cout << genFamily(base,dig,mask,k) << endl;
                    cnt++;
                }
                if (cnt==8)
                    return 0*printf("%d",res);
            }
            //cout << endl;
        }
    }
}
