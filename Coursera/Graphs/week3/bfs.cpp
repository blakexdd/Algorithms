#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> vert;
  vector<int> distances(adj.size(), INT32_MAX);
  distances[s] = 0;

  vert.push(s);

  while(!vert.empty()){
      int top = vert.front();
      vert.pop();

      if (top == t)
          return distances[t];

      for (int i = 0; i < adj[top].size(); i++){
          if (distances[adj[top][i]] == INT32_MAX){
              vert.push(adj[top][i]);
              distances[adj[top][i]] = distances[top] + 1;
          }
      }
  }

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
