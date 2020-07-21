#include <bits/stdc++.h>
using namespace std;
int n,cnt8,res;
string s;

int main(){
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        if (s[i]=='8')
            cnt8++;
    }
    while(cnt8 && n>=11)
        res++,cnt8--,n-=11;
    cout << res << endl;
}
