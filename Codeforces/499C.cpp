#include <bits/stdc++.h>
using namespace std;
const int N=303;
int n,cnt;
long long int a[N],b[N],c[N],x1,x2,y1,y2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i=0;i<n;i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i=0;i<n;i++) {
        if (a[i]*x1+b[i]*y1+c[i] <0 && a[i]*x2+b[i]*y2+c[i] >0)
            cnt++;
        if (a[i]*x1+b[i]*y1+c[i] >0 && a[i]*x2+b[i]*y2+c[i] <0)
            cnt++;
    }
    cout << cnt << endl;
}
