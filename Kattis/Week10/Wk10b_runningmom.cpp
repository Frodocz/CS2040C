#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2

// unordered_map<int, string> id2City; // map the city id -> city name
unordered_map<string, int> city2Id; // map the city name -> city id
vector<vector<int>> graph;
bool cycleDetected = false;

void detectCyclic(int src, vector<int> &status) {
    status[src] = EXPLORED;
    for (auto v : graph[src]) {
        if (status[v] == UNVISITED) {
            detectCyclic(v, status);
        } else if (status[v] == EXPLORED) {
            // cout << "from " << src << " to " << v << " forms a cycle.\n";
            cycleDetected = true;
        }
    }
    status[src] = VISITED;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int E; cin >> E;
    int V = 0;

    for (int i = 0; i < E; ++i) {
        string src, dest;
        cin >> src >> dest;
        int srcId, destId;
        if (city2Id.find(src) == city2Id.end()) { // new city
            city2Id[src] = V;
            // id2City[V] = src;
            srcId = V++;
            graph.push_back(vector<int>());
        } else {
            srcId = city2Id[src];
        }
        if (city2Id.find(dest) == city2Id.end()) { // new city
            city2Id[dest] = V;
            // id2City[V] = dest;
            destId = V++;
            graph.push_back(vector<int>());
        } else {
            destId = city2Id[dest];
        }
        graph[srcId].push_back(destId);
    }

//    cout << "currently " << V << " cities, " << E << " edges\n";
//    for (int i = 0; i < V; ++i) {
//        cout << id2City[i] << "(" << i << ") -> ";
//        for (auto v : graph[i])
//            cout << id2City[v] << "(" << v << ") ";
//        cout << "\n";
//    }

    string cityToCheck;
    while (cin >> cityToCheck) {
        int idx = city2Id[cityToCheck];
        vector<int> status(V);
        cycleDetected = false;
        detectCyclic(idx, status);
        cout << cityToCheck;
        if (cycleDetected) cout << " safe\n";
        else cout << " trapped\n";
    }

    return 0;
}
