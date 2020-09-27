#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<vector<int> > &adj1,vector<int> &used,
         vector<int> &order, vector<int> &sizes, int x) {

  if (sizes[x] == 0 && used[x] != 1){
      for (int j = 0; j < adj1[x].size(); j++)
          sizes[adj1[x][j]]--;

      used[x] = 1;
      order.push_back(x);
      return;
  }

  for (int i = 0; i < adj[x].size(); i++){
      if (used[adj[x][i]] != 1){
          dfs(adj, adj1, used, order, sizes, adj[x][i]);
          if (sizes[x] == 0){
              for (int j = 0; j < adj1[x].size(); j++){
                  sizes[adj1[x][j]]--;
              }

              used[x] = 1;
              order.push_back(x);
          }
      }
  }
}     

vector<int> toposort(vector<vector<int> > adj, vector<vector<int> > adj1, vector<int> &sizes) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here

  for (int i = 0; i < adj.size(); i++){
      dfs(adj, adj1, used, order, sizes, i);
  }

  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adj1(n, vector<int>());
  vector<int> sizes(adj.size());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[y - 1].push_back(x - 1);
    adj1[x - 1].push_back(y - 1);
    sizes[y - 1]++;
  }

  vector<int> order = toposort(adj, adj1, sizes);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
