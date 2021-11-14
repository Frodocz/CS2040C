#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCity; cin >> numCity;

    while (numCity--) {
        int V, E; cin >> V >> E;
        graph G(V, vector<int>());
        vector<bool> visited(V);
        for (int i = 0; i < E; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int CC = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                // cout << i << " ";
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : G[u]) {
                        if (!visited[v]) {
                            q.push(v);
                            visited[v] = true;
                            // cout << v << " ";
                        }
                    }
                }
                ++CC;
            }
        }

        cout << CC - 1 << "\n";
    }

    return 0;
}
