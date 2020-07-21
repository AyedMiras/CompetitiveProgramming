#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=4040;
char s[N];
int n;
ll a,cnt,ind,cum[N],sum[N*N];

int main() {
    scanf("%d %s",&a,s);
    for (int i=0;s[i];i++)
        cum[i] = s[i]-'0'+(i?cum[i-1]:0),ind++;
    n=ind,ind=0;
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)
            sum[ind++]=cum[j]-(i?cum[i-1]:0);
    sort(sum,sum+(n*(n+1))/2);
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            ll curr=cum[j]-(i?cum[i-1]:0);
            if (curr && a%curr==0)
                cnt+=upper_bound(sum,sum+(n*(n+1))/2,a/curr)-lower_bound(sum,sum+(n*(n+1))/2,a/curr);
            else if (!a && curr)
                cnt+=upper_bound(sum,sum+(n*(n+1))/2,0)-lower_bound(sum,sum+(n*(n+1))/2,0);
            else if (!a && !curr)
                cnt+=(n*(n+1))/2;
        }
    }
    printf("%I64d\n",cnt);
}
