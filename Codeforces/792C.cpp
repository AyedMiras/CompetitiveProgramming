#include <bits/stdc++.h>
using namespace std;
string s;
bool flag;
int cnt[3];

int main() {
    cin >> s;
    for (int i=0;s[i];i++) {
        if (s[i]!='0' && (s[i]-'0')%3 == 0 )
            flag=1;
        cnt[(s[i]-'0')%3]++;
    }
    int l = min(cnt[1],cnt[2]);
    if (!l && !flag && cnt[0])
        return 0*printf("0\n");
    flag=0;
    int l1 = 3*(cnt[1]/3) + min(cnt[1]%3,cnt[2]%3);
    int l2 = 3*(cnt[2]/3) + min(cnt[1]%3,cnt[2]%3);
    int cmp1=0,cmp2=0;
    for (int i=0;s[i];i++) {
        if ((s[i]-'0')%3==1 && cmp1 < l1)
            cout << s[i],cmp1++,flag=1;
        if ((s[i]-'0')%3==2 && cmp2 < l2)
            cout << s[i],cmp2++,flag=1;
        if ((s[i]-'0')%3==0 && s[i]!='0')
            cout << s[i],flag=1;
        if (s[i]=='0' && flag)
            cout << s[i];
    }
    if (!flag)
        cout << -1 << endl;
}
