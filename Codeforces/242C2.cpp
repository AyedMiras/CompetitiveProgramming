#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N=(ll)1e9;
ll n,x0,x1,y0,y1,r,a,b;
int dx[8],dy[8];
map<ll,int> dist;

void init() {
    int ind = 0;
    for (int i=-1;i<=1;i++)
        for (int j=-1;j<=1;j++)
            if (i || j)
                dx[ind]=i,dy[ind++]=j;
}

int isValid(int i,int j) {
    return i>=0 && j>=0 && i<N && j<N;
}

void bfs() {
    queue<ll> q;
    q.push(x0+N*y0);
    dist[x0+N*y0]=0;
    while(!q.empty()) {
        int i = q.front()%N;
        int j = q.front()/N;
        if (i==x1 && j==y1) return;
        q.pop();
        for (int k=0;k<8;k++) {
            int ii = i+dx[k],jj= j+dy[k];
            if (isValid(ii,jj) && dist.count(ii+N*jj) && dist[ii+N*jj]==-1) {
                q.push(ii+N*jj);
                dist[ii+N*jj] =dist[i+N*j]+1;
            }
        }
    }
}

int main() {
    init();
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    x0--,y0--,x1--,y1--;
    for (int i=0;i<n;i++) {
        cin >> r >> a >> b;
        r--,a--,b--;
        for (int j=a;j<=b;j++)
            dist[r+N*j] = -1;
    }
    bfs();
    cout << dist[x1+N*y1] << endl;
}
