#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    if (n==1)
        return 0*printf("1\n");
    if (n==3)
        return 0*printf("1 1 3\n");
    int i=1,cnt=0;
    while(i<=n){
        for (int j=i;j<=n;j+=2*i)
            cout << i << " \n"[++cnt==n];
        i*=2;
    }

}
