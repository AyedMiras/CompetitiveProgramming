#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n;
char a[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<=900;i++) {
        int s=0,seg=0;
        for (int j=0;j<n;j++) {
            s+=(a[j]-'0');
            if (s==i)
                s=0,seg++;
        }
        if (!s && seg>=2) {
            return 0*printf("YES\n");
        }
    }
    cout << "NO" << endl;
}
