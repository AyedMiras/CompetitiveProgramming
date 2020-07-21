#include <bits/stdc++.h>
using namespace std;
int dx[8] ={-1,-1,-1,0 ,0, 1,1,1};
int dy[8] ={-1, 0, 1,-1,1,-1,0,1};
int si,sj,ti,tj;
bool vis[70];
int dist[70];
int parent[70];
string dir[8];

bool isValid(int i, int j) {
    if (i>=0 && j>=0 && i<8 && j<8) return 1;
    return 0;
}

int bfs() {
    queue<int> q;
    q.push(si + 8*sj);
    vis[si+8*sj] = true;
    dist[si + 8*sj] = 0;
    while(!q.empty()) {
        if (q.front() == ti + 8*tj) return dist[q.front()];
        int i = q.front()%8;
        int j = q.front()/8;
        q.pop();
        for (int k=0;k<8;k++) {
            if (isValid(i+dx[k],j+dy[k]) && !vis[i+dx[k] + 8*(j+dy[k])]) {
                vis[i+dx[k] + 8*(j+dy[k])] = true;
                parent[i+dx[k] + 8*(j+dy[k])] = i+8*j;
                dist[i+dx[k] + 8*(j+dy[k])] = dist[i+8*j]+1;
                q.push(i+dx[k] + 8*(j+dy[k]));
            }
        }
    }
    return -1;
}
void init() {
    char c;
    cin >> c; si = c -'a';
    cin >> c; sj = c -'1';
    cin >> c; ti = c -'a';
    cin >> c; tj = c -'1';
    memset(parent,-1,sizeof(parent));
    dir[0] ="LD";dir[1]="L";dir[2]="LU";
    dir[3]="D";dir[4]="U";dir[5]="RD";
    dir[6]="R";dir[7]="RU";
}

int main() {
    init();
    cout << bfs() << endl;
    vector<int> p;
    int ind = ti+8*tj;
    p.push_back(ind);
    while(parent[ind] != -1) {
        p.push_back(parent[ind]);
        ind = parent[ind];
    }
    for (int l=p.size()-1;l>0;l--) {
        int i = p[l]%8;
        int j = p[l]/8;
        int ii = p[l-1]%8;
        int jj = p[l-1]/8;
        for (int k=0;k<8;k++) {
            if (i+dx[k] == ii && j+dy[k] == jj) {
                cout << dir[k] << endl;
                break;
            }
        }
    }
}
