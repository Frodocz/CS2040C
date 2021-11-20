#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9

ll cnt = 0;
vector<vii> AL;
vi parent;

void process(ll d) {
    for (auto [v, w] : AL[d]) {
        if (v == parent[d]) {
            cnt += w;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll V, E; cin >> V >> E;
    AL.assign(V, vii());
    while (E--) {
        int u, v, w; cin >> u >> v >> w;
        AL[u - 1].emplace_back(v - 1, w);
        AL[v - 1].emplace_back(u - 1, w);
    }

    int s = 0;
    // using O((V + E) log V) (Modified) Dijkstra's algorithm
    vi dist(V, INF); dist[s] = 0;               // INF = 1e9 here
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({0, s}); // min heap
    parent.assign(V, -1); parent[0] = 0;

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                   // main loop
        auto [d, u] = pq.top(); pq.pop();   // shortest unvisited u
        if (d > dist[u]) continue;          // a very important check
        for (auto &[v, w] : AL[u]) {        // all edges from u
            if (dist[v] > dist[u] + w) {    // relax operation
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});      // enqueue better pair
                parent[v] = u;
            }
        }
    }

    ll d = V - 1;
    while (parent[d] != 0) {
        process(d);
        d = parent[d];
    }
    process(d);
    cout << cnt;

    return 0;
}
