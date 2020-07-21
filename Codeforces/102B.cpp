#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
string s;
int cnt=0;

int main() {
    cin >> s;
    while(s.length()!=1) {
        int n=0;
        char ss[N];
        for (int i=0;s[i];i++)
            n+= (s[i]-'0');
        sprintf(ss,"%d",n);
        s = string(ss);
        cnt++;
    }
    cout << cnt << endl;
}
