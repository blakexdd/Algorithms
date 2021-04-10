#include <iostream>
#include <list>
#include <bits/stdc++.h>
#include <limits.h>

class DisjointSets
{
    int *parent, *rnk;
    int n;

public:
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

class Graph
{
    int V, E;
    std::list<int> *adj;
    std::map<int, bool> visited;
    std::list<std::pair<int, int>> *adjWeigh;
    std::vector<std::pair<int, std::pair<int, int>>> e;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new std::list<int>[V];
        adjWeigh = new std::list<std::pair<int, int>>[V];
    }

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void addEdge(int u, int v, int w)
    {
        adjWeigh[u].push_back(std::make_pair(v, w));
        adjWeigh[v].push_back(std::make_pair(u, w));
    }

    void addWeightedEdge(int u, int v, int w)
    {
        e.push_back({w, {u, v}});
    }

    void DFS(int v)
    {
        visited[v] = true;
        std::cout << v << " ";

        std::list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }

    void BFS(int s)
    {
        bool *visited = new bool[V];
        std::list<int> queue;

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        visited[s] = true;
        queue.push_back(s);

        std::list<int>::iterator i;
        while (!queue.empty())
        {
            s = queue.front();
            std::cout << s << " ";
            queue.pop_front();

            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }

    void Dijsktra(int src)
    {
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;
        std::vector<int> dist(V, INT_MAX);
        pq.push(std::make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            std::list<std::pair<int, int>>::iterator i;
            for (i = adjWeigh[u].begin(); i != adjWeigh[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }

        std::cout << "V dist\n";
        for (int i = 0; i < V; i++)
        {
            std::cout << i << " " << dist[i] << "\n";
        }
    }

    int Kruskal()
    {
        int mst_wt = 0;
        std::sort(e.begin(), e.end());
        DisjointSets ds(V);

        std::vector<std::pair<int, std::pair<int, int>>>::iterator i;
        for (i = e.begin(); i != e.end(); i++)
        {
            int u = i->second.first;
            int v = i->second.second;
            int set_u = ds.find(u);
            int set_v = ds.find(v);

            if (set_u != set_v)
            {
                std::cout << u << "  " << v << "\n";
                mst_wt += i->first;
                ds.merge(set_u, set_v);
            }
        }

        return mst_wt;
    }
};

int main()
{
    Graph notWeightedGraph(4);
    notWeightedGraph.addEdge(0, 1);
    notWeightedGraph.addEdge(0, 2);
    notWeightedGraph.addEdge(1, 2);
    notWeightedGraph.addEdge(2, 0);
    notWeightedGraph.addEdge(2, 3);
    notWeightedGraph.addEdge(3, 3);

    Graph weightedGraph(9);
    weightedGraph.addEdge(0, 1, 4);
    weightedGraph.addEdge(0, 7, 8);
    weightedGraph.addEdge(1, 2, 8);
    weightedGraph.addEdge(1, 7, 11);
    weightedGraph.addEdge(2, 3, 7);
    weightedGraph.addEdge(2, 8, 2);
    weightedGraph.addEdge(2, 5, 4);
    weightedGraph.addEdge(3, 4, 9);
    weightedGraph.addEdge(3, 5, 14);
    weightedGraph.addEdge(4, 5, 10);
    weightedGraph.addEdge(5, 6, 2);
    weightedGraph.addEdge(6, 7, 1);
    weightedGraph.addEdge(6, 8, 6);
    weightedGraph.addEdge(7, 8, 7);

    Graph weightedGraphVertexEdge(9, 14);
    weightedGraphVertexEdge.addWeightedEdge(0, 1, 4);
    weightedGraphVertexEdge.addWeightedEdge(0, 7, 8);
    weightedGraphVertexEdge.addWeightedEdge(1, 2, 8);
    weightedGraphVertexEdge.addWeightedEdge(1, 7, 11);
    weightedGraphVertexEdge.addWeightedEdge(2, 3, 7);
    weightedGraphVertexEdge.addWeightedEdge(2, 8, 2);
    weightedGraphVertexEdge.addWeightedEdge(2, 5, 4);
    weightedGraphVertexEdge.addWeightedEdge(3, 4, 9);
    weightedGraphVertexEdge.addWeightedEdge(3, 5, 14);
    weightedGraphVertexEdge.addWeightedEdge(4, 5, 10);
    weightedGraphVertexEdge.addWeightedEdge(5, 6, 2);
    weightedGraphVertexEdge.addWeightedEdge(6, 7, 1);
    weightedGraphVertexEdge.addWeightedEdge(6, 8, 6);
    weightedGraphVertexEdge.addWeightedEdge(7, 8, 7);

    std::cout << "BFS: \n";
    notWeightedGraph.BFS(2);
    std::cout << "\nDFS: \n";
    notWeightedGraph.DFS(2);
    std::cout << "\nDijkstra: \n";
    weightedGraph.Dijsktra(0);
    std::cout << "\nKruskal: \n";
    weightedGraphVertexEdge.Kruskal();

    return 0;
}