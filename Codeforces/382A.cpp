#include <bits/stdc++.h>
using namespace std;
string s,w,l,r;
int ind;

int main() {
    cin >> s >> w;
    for (int i=0;s[i];i++)
        if (s[i]=='|')
            ind = i;
    l = s.substr(0,ind);
    r = s.substr(ind+1);
    for (int i=0;w[i];i++)
        l.length() < r.length()?l+=w[i]:r+=w[i];
    if (l.length()==r.length())
        cout << l << '|' << r << endl;
    else
        cout << "Impossible" << endl;

}
