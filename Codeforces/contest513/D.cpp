#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
ull gcd(ull a, ull b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n,m,r,z,l,k,h,t,q ; char c ;
ll ans,a,b,dig,p; string s ;
const ll MOD = 1e9 + 7 ;
vector < string > v,rev ;
vector < int > yes;
ll occ[10002];
vector < pair < ll , ll > > edges ;
vector < ll > lft,rght;

void solve()
{

    cin>>n;

	for(int i=0;i<n;i++) {
        ll u,v ;
        cin>>u>>v;
        lft.pb(u);
        rght.pb(v);
	}
	sort(all(lft));
	sort(all(rght));
	ans = n ;
	for(int i=0;i<n;i++) ans+=max(lft[i],rght[i]);

	cout<<ans<<'\n';



      }



int main()
{
     ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    //freopen("out.txt","w",stdout);
   // freopen("test.in","r",stdin);

    solve();



return 0;
}
