#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int MAX = (int)1e9;
int n,k,a[N],ind;

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    int m1n = MAX;
    for (int i=0;i<k;i++) {
        int s =0;
        for (int j=i;j<n;j+=k)
            s+=a[j];
        if (s<m1n)
            m1n = s,ind=i+1;
    }
    cout << ind << endl;
}
