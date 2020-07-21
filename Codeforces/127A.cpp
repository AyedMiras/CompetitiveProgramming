#include <bits/stdc++.h>
using namespace std;
int n,k,x[105],y[105];
double sum;

double sqr(double a) {
    return a*a;
}

double eucDist(double x1, double y1, double x2, double y2) {
    return sqrt( sqr(x1-x2) + sqr(y1-y2));
}

int main() {
    cout.precision(10);
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    for (int i=0;i<n-1;i++)
        sum+=eucDist(x[i],y[i],x[i+1],y[i+1]);
    cout << fixed <<  sum*k/50 << endl;

}
