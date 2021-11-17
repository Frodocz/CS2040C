#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, q, s;
    while (cin >> V >> E >> q >> s) {
        if (V == 0) break;
        vector<vii> AL(V, vii());
        while (E--) {
            int u, v, w; cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        // Bellman Ford's routine, basically = relax all E edges V-1 times
        vi dist(V, INF); dist[s] = 0;               // INF = 1e9 here
        for (int i = 0; i < V - 1; ++i) {           // total O(V*E)
            bool modified = false;                  // optimization
            for (int u = 0; u < V; ++u) {           // those two loops = O(E)
                if (dist[u] != INF) {               // important check
                    for (auto &[v, w] : AL[u]) {    // C++17 style
                        if (dist[v] > dist[u] + w) {
                            dist[v] = dist[u] + w;  // relax operation
                            modified = true;        // optimization
                        }
                    }
                }
            }
            if (!modified) break;                   // optimization
        }

        while (q--) {
            int query; cin >> query;
            if (dist[query] == INF) cout << "Impossible\n";
            else cout << dist[query] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
