#include <bits/stdc++.h>
using namespace std;
int x[3],y[3],area,cnt,m,mInd;
map<int,char> logo;

int sqr(int x) {
    return x*x;
}

int main() {
    for(int i=0;i<3;i++)
        cin >> x[i] >> y[i];
    for(int i=0;i<3;i++) {
        area+=x[i]*y[i];
        logo[i]='A'+i;
    }
    if(sqr((int)sqrt(area))!=area)
        return cout << -1 << endl,0;
    for(int i=0;i<3;i++)
        if (x[i]>=m || y[i]>=m)
            m=max(x[i],y[i]),mInd=i;
    for(int i=0;i<3;i++)
        if (x[i]==m || y[i]==m)
            cnt++;
    if(m!=(int)sqrt(area))
        return cout << -1 << endl,0;
    if(cnt==3) {
        cout << m << endl;
        for(int k=0;k<3;k++) {
            for(int j=0;j<min(x[k],y[k]);j++) {
                for(int i=0;i<m;i++)
                    cout << logo[k];
                cout << endl;
            }
        }
        return 0;
    }
    int l1=-1,l2=-1;
    if (x[(mInd+1)%3]+y[(mInd+2)%3]==m && y[(mInd+1)%3]==x[(mInd+2)%3])
        l1=x[(mInd+1)%3],l2=y[(mInd+2)%3];
    if (x[(mInd+1)%3]+x[(mInd+2)%3]==m && y[(mInd+1)%3]==y[(mInd+2)%3])
        l1=x[(mInd+1)%3],l2=x[(mInd+2)%3];
    if (y[(mInd+1)%3]+x[(mInd+2)%3]==m && x[(mInd+1)%3]==y[(mInd+2)%3])
        l1=y[(mInd+1)%3],l2=x[(mInd+2)%3];
    if (y[(mInd+1)%3]+y[(mInd+2)%3]==m && x[(mInd+1)%3]==x[(mInd+2)%3])
        l1=y[(mInd+1)%3],l2=y[(mInd+2)%3];
    if(l1==-1)
        return cout << 0 << endl,0;
    cout << m << endl;
    for(int j=0;j<min(x[mInd],y[mInd]);j++) {
        for(int i=0;i<m;i++)
            cout << logo[mInd];
        cout << endl;
    }
    for(int j=min(x[mInd],y[mInd]);j<m;j++) {
        for(int i=0;i<l1;i++)
            cout << logo[(mInd+1)%3];
        for(int i=0;i<l2;i++)
            cout << logo[(mInd+2)%3];
        cout << endl;
    }
    return 0;
}

