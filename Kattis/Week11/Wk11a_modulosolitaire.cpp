#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

// #define INF 1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n, s; cin >> m >> n >> s; // modulus, branches, source
    vii pairs;
    while (n--) {
        ll ai, bi; cin >> ai >> bi;
        pairs.emplace_back(ai, bi);
    }

    vi moves(m);
    moves[s] = 1;
    queue<ll> q; q.push(s);
    while (!q.empty()) {
        auto front = q.front(); q.pop();
        for (auto i = 0; i < pairs.size(); ++i) {
            auto next = (front * pairs[i].first + pairs[i].second) % m;
            if (moves[next] == 0) {
                moves[next] += moves[front] + 1;
                q.push(next);
            }
        }
        if (moves[0]) break;
    }

    cout << moves[0] - 1;

    return 0;
}
