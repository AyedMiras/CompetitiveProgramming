#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n,a[N],s;
bool exist[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i],exist[a[i]]=1;
    for (int i=1;i<=n;i++)
        if (exist[i]) s++;
    cout << n-s << endl;
}
