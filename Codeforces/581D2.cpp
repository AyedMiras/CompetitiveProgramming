#include <bits/stdc++.h>
using namespace std;
int x[3],y[3],ind,l,area;

int main() {
    for(int i=0;i<3;i++)
        cin >> x[i] >> y[i];
    for(int i=0;i<3;i++) {
        if(y[i]>x[i])
            swap(x[i],y[i]);
        if(x[i]>l)
            l=x[i],ind=i;
        area+=x[i]*y[i];
    }
    if(l*l!=area)
        return cout << -1 << endl,0;
    cout << l << endl;
    int l0=l;
    for(int i=0;i<3;i++) {
        if(x[i]==l) {
            for(int j=0;j<y[i];j++)
                cout << string(l,'A'+i) << endl;
            l0-=y[i];
        }
    }
    for(int i=0;i<l0;i++) {
        for(int j=0;j<3;j++) {
            if(j!=ind) {
                if(x[j]==l0)
                    cout << string(y[j],'A'+j);
                else
                    cout << string(x[j],'A'+j);
            }
        }
        cout << endl;
    }
}
