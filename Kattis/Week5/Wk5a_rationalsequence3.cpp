#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void simulate(deque<bool> &path) {
    ll p = 1, q = 1;
    for (auto b : path) { // false --> left child; true --> right child
        if (b)
            p = p + q;
        else
            q = p + q;
    }
    cout << p << "/" << q << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;
    while (p--) {
        ll k, n;
        cin >> k >> n;
        cout << k << " ";

        deque<bool> path;
        while (n > 1) {
            path.push_front(n % 2); // false --> left child; true --> right child
            n /= 2;
        }
        simulate(path);
    }
    return 0;
}