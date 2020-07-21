#include <bits/stdc++.h>
using namespace std;
int n,cnt,prime[3010];

int main() {
    cin >> n;
    for (int i=2;i<=n;i++)
        if (!prime[i])
            for (int j=2;j*i<=n;j++)
                prime[i*j]++;
    for (int i=2;i<=n;i++)
        if (prime[i]==2) cnt++;
    cout << cnt << endl;
}
