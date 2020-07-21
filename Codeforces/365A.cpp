#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
string a;

bool good(string s) {
    bool dig[10];
    int c=0;
    memset(dig,0,sizeof(dig));
    for (int i=0;i<s.length();i++) {
        if (s[i]-'0' <= k && !dig[s[i]-'0'])
            dig[s[i]-'0']=true,c++;
    }
    return (c==k+1);
}

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (good(a))
            cnt++;
    }
    cout << cnt << endl;
}
