#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,p[N],prz[5];
long long int cnt[5];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> p[i];
    for (int i=0;i<5;i++) cin >> prz[i];
    long long int pt=0;
    for (int i=0;i<n;i++) {
        pt+=p[i];
        for (int j=4;j>=0;j--) {
            if (pt>=prz[j]) cnt[j]+=pt/prz[j],pt= pt%prz[j];
        }
    }
    for (int i=0;i<5;i++)
        cout << cnt[i] << " \n"[i==4];
    cout << pt << endl;

}
