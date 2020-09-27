#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void visit(vector<bool> &visited, vector<vector<int> > &adj, int y, int currV, int &res){
    if (!visited[currV]){
        visited[currV] = true;

        //std::cout << "V: " << currV << "\n";

        vector<int> neibrs = adj[currV];

        for (int i = 0; i < neibrs.size(); i++){
            //std::cout << "neib: " << neibrs[i] << "\n";
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

int acyclic(vector<vector<int> > &adj) {
  //write your code here

  for (int i = 0; i < adj.size(); i++){
      int r = 0;
      int &res = r;
      vector<bool> visited(adj.size());
      visit(visited, adj, i, i, res);
      if (res == 1)
          return 1;
  }

  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;

    std::cin >> x >> y;

    adj[x - 1].push_back(y - 1);
  }

  std::cout << acyclic(adj);
}
