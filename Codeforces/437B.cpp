#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int sum,s,lim,cnt;
pair<int,int> a[N];
vector<int> num;

int main() {
    cin >> s >> lim;
    for (int i=0;i<lim;i++) a[i]=make_pair((i+1)&(-(i+1)),i+1);
    sort(a,a+lim);
    for (int i=lim-1;i>=0;i--)
        if (sum+a[i].first<=s)
            sum+=a[i].first,cnt++,num.push_back(a[i].second);
    if (sum !=s) return 0*printf("-1\n");
    cout << cnt << endl;
    for (int i=0;i<num.size();i++)
        cout << num[i] << " \n"[i==num.size()-1];

}
