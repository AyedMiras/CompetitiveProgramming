#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n;
double p[N];

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n,greater<double>());
    double maxProb=p[0];
    for(int i=1;i<n;i++) {
        double ors=0;
        for(int j=0;j<=i;j++) {
            double ands=1;
            for (int k=0;k<=i;k++) {
                if (k==j)
                    ands*=p[k];
                else
                    ands*=(1-p[k]);
            }
            ors+=ands;
        }
        if(ors<=maxProb)
            break;
        maxProb=ors;
    }
    cout << setprecision(15) << maxProb << endl;
}
