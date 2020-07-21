#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int T,st,en;
int sieve[N],dist[N],parent[N];
int pwr[4]= {1,10,100,1000};
int d[4];

void eras() {
    for (int i=2;i<N;i++)
        if (!sieve[i])
            for (int j=2;i*j<N;j++)
                sieve[i*j]=1;
}

int bfs() {
    queue<int> q;
    dist[st]=0;
    q.push(st);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if (top==en)
            return dist[top];
        for (int i=0;i<4;i++)
            d[i] = (top/pwr[i])%10;
        for (int i=0;i<=9;i++)
            for (int j=0;j<4;j++)
                //case first digit mustn't be 0
                if ( !(j==3 && !i) && dist[top-d[j]*pwr[j] + i*pwr[j]]==-1 && !sieve[top-d[j]*pwr[j] + i*pwr[j]])
                    dist[top-d[j]*pwr[j] + i*pwr[j]]=dist[top]+1,q.push(top-d[j]*pwr[j] + i*pwr[j]);//,parent[top-d[j]*pwr[j] + i*pwr[j]]=top;

    }
    return -1;
}

int main() {
    eras();
    cin >> T;
    while(T--){
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        cin >> st >> en;
        cout << bfs() << endl;
        /*int ind =en;
        while(ind!=-1)
            cout << ind << endl,ind=parent[ind];
        */
    }
}
