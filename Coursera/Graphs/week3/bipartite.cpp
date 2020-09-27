#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::set;
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
    queue<int> vert;
    vector<bool> visited(adj.size());
    set<int> v;

    for (int i = 0; i < adj.size(); i++){
        if (adj[i].size() > 0)
            v.insert(i);
    }

    if (adj.size() == 0)
        return 0;

    while(!v.empty()){
        int s = *v.begin();
        if (adj[s].size() == 0)
            continue;

        vector<int> distances(adj.size(), INT32_MAX);
        distances[s] = 0;

        visited[s] = true;
        v.erase(s);

        vert.push(s);

        while(!vert.empty()){
            int top = vert.front();
            vert.pop();

            visited[top] = true;
            v.erase(top);

            for (int i = 0; i < adj[top].size(); i++){
                if (distances[adj[top][i]] == INT32_MAX){
                    vert.push(adj[top][i]);
                    distances[adj[top][i]] = distances[top] + 1;
                }else if(((distances[adj[top][i]] - distances[top]) % 2 == 0
                         || (distances[adj[top][i]] - distances[top]) == 0) && adj[top][i] != top){
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;

    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
