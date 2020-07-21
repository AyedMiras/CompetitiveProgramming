#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
ll n,t,a[N],cnt;
pair<ll,int> cum[N];
vector<int> st[4*N];
vector<int>::iterator it;

void build(int si,int ss,int se) {
    if (ss==se){
        st[si].push_back(cum[ss].second);
        return;
    }
    int mid=ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    /*for (it=st[2*si+1].begin();it!=st[2*si+1].end();++it)
        st[si].insert(*it);
    for (it=st[2*si+2].begin();it!=st[2*si+2].end();++it)
        st[si].insert(*it);*/
    merge(st[2*si+1].begin(), st[2*si+1].end(),
          st[2*si+2].begin(), st[2*si+2].end(),
          back_inserter(st[si]));
}

void print(int si,int ss,int se) {
    cout << ss << " " << se << ":" << endl;
    for (it=st[si].begin();it!=st[si].end();++it)
        cout << *it << " ";
    cout << endl;
    if(ss==se)
        return;
    int mid=ss+(se-ss)/2;
    print(2*si+1,ss,mid);
    print(2*si+2,mid+1,se);
}

ll query(int si,int ss,int se,int qs,int qe,int i) {
    if (ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe) {
        //cout << qs << " " << qe << " " << ss << " " << se << " " << i << ":" << endl;
        //cout <<  distance(st[si].lower_bound(i),st[si].end())<< endl;
        return st[si].end()-upper_bound(st[si].begin(),st[si].end(),i);
    }
    int mid=ss+(se-ss)/2;
    return query(2*si+1,ss,mid,qs,qe,i)+query(2*si+2,mid+1,se,qs,qe,i);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> t;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++) {
        cum[i].first=a[i]+cum[i-1].first;
        cum[i].second=i;
    }
    sort(cum,cum+n+1);
    build(0,0,n);
    //print(0,0,n);
    for (int i=0;i<n+1;i++){
        int l=lower_bound(cum,cum+n+1,make_pair(cum[i].first+t,-1))-cum;
        int res = (l?query(0,0,n,0,l-1,cum[i].second):0);
        //cout << "0 " << l << " " << cum[i].second << ":" << res << endl;
        cnt+=res;
    }
    cout << cnt << endl;
}
