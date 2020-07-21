#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,ax,ay,bx,by,cx,cy;
int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
bool check[N][N],vis[N][N];

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
}

bool bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(bx,by));
    vis[bx][by]=1;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i==cx && j==cy)
            return 1;
        for (int k=0;k<8;k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            if (isValid(ii,jj) && !vis[ii][jj] && !check[ii][jj]){
                vis[ii][jj]=1;
                q.push(make_pair(ii,jj));
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    ax--,ay--,bx--,by--,cx--,cy--;
    check[ax][ay]=1;
    for (int k=0;k<8;k++)
        for (int i=0;i<n;i++)
            if (isValid(ax+dx[k]*i,ay+dy[k]*i))
                check[ax+dx[k]*i][ay+dy[k]*i]=1;
    cout << (bfs()?"YES":"NO") << endl;
}
