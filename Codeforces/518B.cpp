#include <bits/stdc++.h>
using namespace std;
const int N=200200;
string s,t;
int lowAlpha[26],upperAlpha[26],glued[N],y,w;

int main() {
    ios::sync_with_stdio(0);
    cin >> s >> t;
    for (int i=0;t[i];i++) {
        if (t[i]>='a' && t[i]<='z')
            lowAlpha[t[i]-'a']++;
        else
            upperAlpha[t[i]-'A']++;
    }
    for (int i=0;s[i];i++) {
        if (s[i]>='a' && s[i]<='z') {
            if (lowAlpha[s[i]-'a'])
                lowAlpha[s[i]-'a']--,glued[i]=1,y++;
        }
        else {
            if (upperAlpha[s[i]-'A'])
                upperAlpha[s[i]-'A']--,glued[i]=1,y++;
        }
    }

    for (int i=0;s[i];i++) {
        if (!glued[i] && s[i]>='a' && s[i]<='z') {
            if (upperAlpha[s[i]-'a'])
                upperAlpha[s[i]-'a']--,w++;
        }
        else if (!glued[i] && s[i]>='A' && s[i]<='Z') {
            if (lowAlpha[s[i]-'A'])
                lowAlpha[s[i]-'A']--,w++;
        }
    }
    cout << y << " " << w << endl;
}
