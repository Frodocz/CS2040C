#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;

struct edge {
    ll u, v, w;
    edge(ll s, ll d, ll weight) : u(s), v(d), w(weight) {};
};

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9

// Dijkstra's Algorithm find the shortest path from 1 to 0
// then remove edges in the shortest path and see if there's a path from 0 to 1
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll V, E; cin >> V >> E;
    vector<vii> AL(V, vii());
    vector<edge> EL;
    while (E--) {
        ll u, v, w; cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
        EL.emplace_back(u, v, w);
    }

    ll s = 1;
    vi dist(V, INF); dist[s] = 0;

    // Original Dijkstra's algorithm
    set<ii> pq;                                    // balanced BST version
    for (int u = 0; u < V; ++u)                    // dist[u] = INF
        pq.insert({dist[u], u});                   // but dist[s] = 0
    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto[d, u] = *pq.begin();                 // shortest unvisited u
        pq.erase(pq.begin());
        for (auto &[v, w] : AL[u]) {               // all edges from u
            if (dist[u] + w >= dist[v]) continue;  // not improving, skip
            pq.erase(pq.find({dist[v], v}));       // erase old pair
            dist[v] = dist[u] + w;                 // relax operation
            pq.insert({dist[v], v});               // enqueue better pair
        }
    }

    vector<vi> AL2(V); // without the shortest path
    for (ll i = 0; i < V; ++i) {
        auto adj = AL[i];
        // cout << i << " -> ";
        for (auto [v, w] : AL[i]) {
            // cout << "(" << v << ", " << w << ") ";
            if (dist[v] + w == dist[i]) continue;
            AL2[i].push_back(v);
        }
        // cout << endl;
    }

    queue<ll> bq; bq.push(0);
    vector<bool> visited(V, false);
    vi parent(V, -1); visited[0] = true;

    while (!bq.empty()) {
        ll u = bq.front(); bq.pop();
        for (auto v : AL2[u]) {
            if (!visited[v]) {
                bq.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

    ll d = 1;
    if (parent[d] == -1)
        cout << "impossible";
    else {
        stack<ll> st; st.push(d);
        while (parent[d] != 0) {
            st.push(parent[d]);
            d = parent[d];
        }
        cout << st.size() + 1 << " 0 ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }

    return 0;
}
