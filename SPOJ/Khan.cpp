#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int i=0;i<n;i++) {
        in_deg[i]=0;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<graph[i].size();j++) {
            in_deg[graph[i][j]]++;
        }
    }

    queue<int> q;
    for (int i=0;i<n;i++) {
        if(!in_deg[i]) q.push(i);
    }

    vector<int> topSort;
    int cnt=0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        topSort.push_back(top);
        for (int j=0;j<graph[top].size();j++)
            if (!--deg[graph[top][j] )
                q.push(graph[top][j]);
        cnt ++;
    }

    if (cnt > N) printf("Cycle detected\n");
}
