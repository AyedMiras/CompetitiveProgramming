 #include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N];
bool vis[N],res[N];
vector<int> ts;

void topSort(int i){
    vis[i]=1;
    for (int j=i+a[i];j<n;j+=a[i])
        if (!vis[j] && a[j]>a[i])
            topSort(j);
    for (int j=i-a[i];j>=0;j-=a[i])
        if (!vis[j] && a[j]>a[i])
            topSort(j);
    ts.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++)
        if (!vis[i])
            topSort(i);
    for (int k=0;k<ts.size();k++){
        int i=ts[k];
        res[i]=1;
        for (int j=i+a[i];j<n;j+=a[i])
            if (a[j]>a[i])
                res[i]&=res[j];
        for (int j=i-a[i];j>=0;j-=a[i])
            if (a[j]>a[i])
                res[i]&=res[j];
        res[i]=1-res[i];
    }
    for (int i=0;i<n;i++)
        cout << (res[i]?"A":"B");
    cout << endl;
}
