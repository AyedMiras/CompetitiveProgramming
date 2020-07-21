#include <bits/stdc++.h>
using namespace std;
const int N=33;
int T,n,d;
long long int w[N],sum1[1<<(N/2+1)];
pair<long long int, int> sum2[1<<(N/2+1)];

int bits(long long int a, int nn){
    int cnt=0;
    for (int i=0;i<(1<<nn);i++)
        if ((1<<i)&a)
            cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    for (int t=0;t<T;t++) {
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        cin >> n >> d;
        for (int i=0;i<n;i++)
            cin >> w[i];
        for (int i=0;i<(1<<(n/2));i++) {
            for (int j=0;j<n/2;j++)
                if (i&(1<<j))
                    sum1[i]+=w[j];
            //cout << sum1[i] << " ";
        }
        //cout << endl;

        for (int i=0;i<(1<<(n-n/2));i++) {
            for (int j=0;j<(n-n/2);j++)
                if (i&(1<<j))
                    sum2[i].first+=w[j+n/2];
            sum2[i].second=i;
            //cout << sum2[i] << " ";
        }
        sort(sum2,sum2+(1<<(n-n/2)));
        int flag = 0,res=-1;
        for (int i=0;i<(1<<(n/2));i++) {
            pair<long long int,int>* l = lower_bound(sum2,sum2+(1<<(n-n/2)),make_pair(d-sum1[i],-1));
            if (l->first==d-sum1[i]) {
                int b=bits(i,n/2)+bits(l->second,(n-n/2));
                pair<long long int,int>* u = upper_bound(sum2,sum2+(1<<(n-n/2)),make_pair(d-sum1[i],-1));
                if (b!=res) {
                    res=b,flag++;
                    if ( u-l+1 > 1 && bits(i,n/2)+bits(u->second,(n-n/2)) )
                        flag++;
                }
            }
        }
        cout << "Case #" << t+1 << ": ";
        if (flag==1)
            cout << res << endl;
        else if (!flag)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << "AMBIGIOUS" << endl;

    }
}
