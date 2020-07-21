#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,sx,sy,ex,ey;
string s;

int main() {
    cin >> t >> sx >> sy >> ex >> ey >> s;
    for (int i=0;s[i];i++) {
        if (s[i]=='S' && ey<sy) sy--;
        if (s[i]=='E' && ex>sx) sx++;
        if (s[i]=='N' && ey>sy) sy++;
        if (s[i]=='W' && ex<sx) sx--;
        if (sx==ex && sy==ey) return 0*printf("%d\n",i+1);
    }
    cout << -1 << endl;
}
