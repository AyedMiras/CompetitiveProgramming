#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
string s;
int n,p,cnt;
bool pal[N];

int main() {
    cin >> n >> p >> s;
    for (int i=0;i<n/2;i++) if (s[i]==s[n-i-1]) pal[i]=pal[n-i-1]=true;
    int step=0,ind=p-1,rstep=0,lstep=0,w=n/2;
    while(step<n) {
        if (!pal[ind]) rstep=step;
        ind= (ind+1)%n;
        step++;
    }
    ind=p-1,step=0;
    while(step<n) {
        if (!pal[ind]) lstep=step;
        ind = (ind-1+n)%n;
        step++;
    }
    step = n/2;
    while(step>0) {
        if (!pal[])
    }

}
