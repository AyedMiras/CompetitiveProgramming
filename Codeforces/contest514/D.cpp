#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
const int N=100100;
const int MAX=1e7+100;
int n,x[N],y[N],pos,neg;
double moy;

double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        if (y[i]>0)
            pos=1;
        if (y[i]<0)
            neg=1;
    }
    if (pos&&neg)
        return 0*printf("-1\n");
    for (int i=0;i<n;i++)
        moy+=x[i];
    moy/=n;
    double l=0,r=MAX;
    while(fabs(l-r)>eps){
        double mid=(l+r)/2;
        int cnt=0;
        for (int i=0;i<n;i++)
            if (dist(moy,pos?mid:-mid,x[i],y[i])<=mid)
                cnt++;
        if (cnt==n)
            r=mid;
        else
            l=mid;
    }
    cout << l << endl;
}
