#include <bits/stdc++.h>
using namespace std;
int n,s,t;
string road;

int main() {
    cin >> n >> road;
    for (int i=0;i<road.length();i++) {
        if (road[i]=='.') continue;
        if (road[i]=='L') {
            t=i;
            while(road[i]=='L') i++;
            s=i;
            break;
        }
        else {
            s=i+1;
            while(road[i]=='R') i++;
            t=(road[i]=='L'?i:i+1);
            break;
        }
    }
    cout << s << " " << t << endl;
}
