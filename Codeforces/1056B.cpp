#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M=1010;
ll n,m,k,cnt,sqr[2*M];
int flag;

int main() {
    cin >> n >> m;
    for(int i=1;i*i<=2*M*M;i++) {
        sqr[i]=i*i;
    }
    for(k=1;k<=2*M;k++) {
        for (int i=1;i*i<=2*M*M;i++) {
            if (binary_search(sqr,sqr+2*M,k*m-sqr[i])) {
                flag=1;
                break;
            }
        }
        if (flag)
            break;
    }
    for(ll i=1;k*i*m<2*n*n;i++) {
        cout << k*i*m << endl;
        cnt+=2*(int)sqrt(k*i*m-1);
    }
    cout << cnt << endl;
}
