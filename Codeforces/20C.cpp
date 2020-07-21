#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <functional>
#include <stack>
#define INF 1e11 + 10
using namespace std;

typedef pair<int,long int> ii;
typedef vector< pair< int,long int> > vii;
typedef vector<vector < pair<int,long int> > > vvii;
int V,E;
vvii Graph;

void dijsktra(int src) {
  vector<long long int> dist(V,INF);
  vector <int> parent(V,0);
  priority_queue< ii, vii ,greater<ii> > pq;
  dist[src]=0;

  pq.push(make_pair(0,src));
  while (!pq.empty()) {
    int top =pq.top().second;
    pq.pop();
    for (int i=0;i<Graph[top].size();++i) {
      if (dist[Graph[top][i].first] > dist[top] + Graph[top][i].second) {
        dist[Graph[top][i].first] = dist[top] + Graph[top][i].second;
        parent[Graph[top][i].first] = top;
        pq.push(make_pair(dist[Graph[top][i].first],Graph[top][i].first));
      }
    }
  }
  if (dist[V-1]==INF) cout<< -1<<endl;
  else {
    stack<int> s;
    s.push(V-1);
    while(parent[s.top()]!=src)
        s.push(parent[s.top()]);
    s.push(src);
    int cmp=0;
    while(!s.empty())
        if (!cmp)
            cout<<s.top()+1,s.pop(),cmp++;
        else
            cout<<" "<<s.top()+1,s.pop();
    cout << endl;
  }
}



int main() {
  cout<< LONG_LONG_MAX;
  cin >> V;
  cin >> E;
  Graph.resize(V);
  for (int e=0;e<E;e++) {
    int v1,v2,ed;
    cin >> v1 >> v2 >> ed;
    Graph[v1-1].push_back(make_pair(v2-1,ed));
    Graph[v2-1].push_back(make_pair(v1-1,ed));
  }
  dijsktra(0);
  return 0;
}
