#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int N=100100;
const double EPS=1e-9;
int n,pos,neg;
ld x[N],y[N];

bool lt(ld a, ld b){
    return a<b+EPS;
}

bool isValid(ld m){
    ld l=-1e15,r=1e15;
    for (int i=0;i<n;i++){
        ld c = x[i]*x[i]+y[i]*y[i]-2*m*y[i];
        ld b2 = 4*x[i]*x[i];
        ld delta = b2 - 4*c;
        if (lt(delta,0))
            return 0;
        ld x1 = x[i]+sqrt(delta)/2;
        ld x2 = x[i]-sqrt(delta)/2;
        l = max(l,x2);
        r = min(r,x1);
    }
    return lt(l,r);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        if (y[i]>0)
            pos=1;
        if (y[i]<0)
            neg=1;
    }
    if (pos && neg)
        return cout << "-1" << endl,0;
    if (neg)
        for (int i=0;i<n;i++)
            y[i]=-y[i];
    ld l=0,r=1e15;
    cout.precision(16);
    for (int i=0;i<512;i++){
        long double mid=(l+r)/2;
        isValid(mid)?r=mid:l=mid;
    }
    cout << fixed << l << endl;
}
