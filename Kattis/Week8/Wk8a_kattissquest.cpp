#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, G;
    string cmd;

    map<int, priority_queue<int>> pool; // {E1:G1, E1:G2, E2:G1}

    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd[0] == 'a') { // add X Y
            cin >> E >> G;
            pool[E].push(G);
        } else if (cmd[0] == 'q') { // query X
            cin >> E;
            long long curGold = 0;
            while (!pool.empty()) {
                auto it = pool.lower_bound(E); // find last E(with highest G) or the item just bigger than E
                if (it == pool.end()) --it;
                while (it->first > E && it != pool.begin()) {
                    --it;
                }
                if (it->first > E) break;
                // now we found the last E(with highest G) or the item just bigger than E
                curGold += it->second.top();
                it->second.pop();
                E -= it->first;
                if (it->second.empty()) {
                    pool.erase(it);
                }
            }
            cout << curGold << "\n";
        }
    }

    return 0;
}
