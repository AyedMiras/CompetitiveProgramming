#include <iostream>
#include <algorithm>
#define MAX (int)1e5 + 10
using namespace std;
int n,m;
long long int v[MAX],sorted_v[MAX],sum_v[MAX],sum_sorted_v[MAX];

void _fill() {
    sum_v[0] = v[0];
    sum_sorted_v[0] = sorted_v[0];
    for (int i=1;i<n;i++){
        sum_v[i]+=sum_v[i-1] + v[i];
        sum_sorted_v[i]+=sum_sorted_v[i-1] + sorted_v[i];
    }
}
int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> v[i], sorted_v[i] = v[i];
    sort(sorted_v,sorted_v+n);
    _fill();
    cin >> m;
    for (int i=0;i<m;i++) {
       int l,r,type;
       cin >>  type >> l >> r;
       if (type-1) {
            if (l-1)
                cout << sum_sorted_v[r-1] - sum_sorted_v[l-2] << endl;
            else
                cout << sum_sorted_v[r-1] << endl;
       }
       else {
            if (l-1)
                cout << sum_v[r-1] - sum_v[l-2] << endl;
            else
                cout << sum_v[r-1] << endl;
       }
    }
}

