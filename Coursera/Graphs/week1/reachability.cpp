#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void visit(vector<bool> &visited, vector<vector<int> > &adj, int y, int currV, int &res){
    if (!visited[currV]){
        visited[currV] = true;

        if (currV == y){
            res = 1;
            return;
        }

        vector<int> neibrs = adj[currV];

        for (int i = 0; i < neibrs.size(); i++){
            if (neibrs[i] == y){
                res = 1;
                return;
            }
            else
                visit(visited, adj, y, neibrs[i], res);
        }
    }

    return;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<bool> visited(adj.size());
  int result = 0;
  int &res = result;

  visit(visited, adj, y, x, res);

  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
