#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi; // {v adj to u}
typedef vector<vi> AdjList; // AdjList[u] --> {v adj to u}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        // while (m--) {
        //     int a, b;
        //     cin >> a >> b;
        // }
        cout << n - 1 << "\n";
    }

    return 0;
}
