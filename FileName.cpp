#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    int V; // Количество вершин
    std::vector<std::vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    // Добавление ребра в граф
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Обход в ширину (BFS)
    void BFS(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // Рекурсивный обход в глубину (DFS)
    void DFS(int start) {
        std::vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

private:
    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);


    std::cout << "BFS: "; //BFS обход с вершины 0
    g.BFS(0);
    std::cout << std::endl;

    std::cout << "DFS: "; //DFS обход с вершины 0
    g.DFS(0);
    std::cout << std::endl;

    return 0;
}