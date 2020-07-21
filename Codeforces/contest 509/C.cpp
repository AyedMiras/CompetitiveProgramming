#include <bits/stdc++.h>
using namespace std;
const int N=200200;
int n,m,d,cnt,day[N];
pair<int,int> a[N];
map<int,int> coffee,ind;
map<int,int>::iterator it;


int main() {
    cin >> n >> m >> d;
    for (int i=0;i<n;i++)
        cin >> a[i].first,a[i].second=i,ind[a[i].first]=i;
    sort(a,a+n);
    for (int i=0;i<n;i++) {
        it = coffee.lower_bound(a[i].first-d);
        if (it==coffee.begin())
            coffee[a[i].first]++,day[a[i].second]=++cnt;
        else {
            --(coffee.begin()->second);
            coffee[a[i].first]++,day[a[i].second]=day[ind[coffee.begin()->first]];
            if (coffee.begin()->second == 0)
                coffee.erase(coffee.begin());
        }
    }
    cout << cnt << endl;
    for (int i=0;i<n;i++)
        cout << day[i] << " \n"[i==n-1];
}
