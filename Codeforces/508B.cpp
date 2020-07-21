#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
    cin >> s;n=s.length();
    int ind=-1;
    for (int i=0;s[i];i++) {
        if ((s[i]-'0')&1) continue;
        ind = i;
        if (s[i]< s[n-1]) {
            swap(s[i],s[n-1]);
            cout << s << endl;
            return 0;
        }
    }
    if (ind!=-1){
        swap(s[ind],s[n-1]);
        cout << s << endl;
        return 0;
    }
    cout << -1 << endl;
}
