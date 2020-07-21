#include <bits/stdc++.h>
using namespace std;
const int N=10010;
const double eps=1e-9;
int k;
double frac[N];

int main() {
    for (int i=1;i<N;i++)
        frac[i]=1.0/i;
    while(cin >> k) {
        cout << k << endl;
        if (k==1) {
            cout << "1/1 = 1/2 + 1/2" << endl;
            continue;
        }
        for (int i=2;i<N;i++) {
            int l=1,r=N;
            while(l<r) {
                int mid = l+(r-l)/2;
                fabs(1.0/k - 1.0/i - 1.0/mid)<eps?l=mid+1:r=mid;
            }
            l--;
            if (k*(i+l)==i*l)
                cout << "1/" << k << " = 1/" << i << " + 1/" << l << endl;
        }
    }
}
