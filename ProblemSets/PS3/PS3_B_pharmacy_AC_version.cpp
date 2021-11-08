#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

typedef enum Type {
    STORE = 0,
    REMOTE = 1,
    FILLED = 2
} Type;

typedef long long ll;
typedef tuple<ll, Type, ll> Order; // dropTime, type, duration
typedef pair<ll, ll> QueueOrder;

bool comp(const Order &a, const Order &b) { // to let a higher than b, return false
    ll dtA, dtB, duA, duB; Type tA, tB;
    // C++17 we can use:
    // auto [dtA, tA, duA] = a; auto [dtB, tB, duB] = b;
    tie(dtA, tA, duA) = a;
    tie(dtB, tB, duB) = b;
    if (dtA != dtB) { // smaller drop time higher
        return dtA > dtB;
    } else {
        if (tA != tB) { // 'R' and 'S', store > remote
            return tA > tB;
        } else {
            return duA > duB;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t; cin >> n >> t;

    ll numStore = 0, numRemote = 0;
    double totalStore = 0, totalRemote = 0;

    vector<Order> orders;
    // vector<Order> orders; // {now, type, duration}
    queue<QueueOrder> storeQueue, remoteQueue; // {now, duration}

    while (n--) {
        ll d; char c; ll k; cin >> d >> c >> k; // d --> drop time
        Type type = (c == 'S') ? STORE : REMOTE;
        orders.push_back(make_tuple(d, type, k));
    }

    make_heap(orders.begin(), orders.end(), comp);

    while (!orders.empty()) {
        // C++17 can use:
        // auto [dropTime, type, duration] = orders.front();
        ll dropTime, duration; Type type; // dropTime is also the current time
        tie(dropTime, type, duration) = orders.front(); // get the highest priority event
        pop_heap(orders.begin(), orders.end(), comp); orders.pop_back(); // process the event
        if (type == STORE) {
            if (t == 0) {
                storeQueue.push( {dropTime, duration} );
            } else {
                --t;
                orders.push_back(make_tuple(dropTime + duration, FILLED, duration)); // final duration
                push_heap(orders.begin(), orders.end(), comp);
                totalStore += duration;
                ++numStore;
            }
        } else if (type == REMOTE) {
            if (t == 0) {
                remoteQueue.push( {dropTime, duration} );
            } else {
                --t;
                orders.push_back(make_tuple(dropTime + duration, FILLED, duration));
                push_heap(orders.begin(), orders.end(), comp);
                totalRemote += duration;
                ++numRemote;
            }
        } else {
            if (!storeQueue.empty()) {
                auto [dt, du] = storeQueue.front(); storeQueue.pop(); // dropTime, duration
                orders.push_back(make_tuple(dropTime + du, FILLED, dropTime - dt + du));
                push_heap(orders.begin(), orders.end(), comp);
                totalStore += dropTime -dt + du;
                ++numStore;
            } else if (!remoteQueue.empty()) {
                auto [dt, du] = remoteQueue.front(); remoteQueue.pop(); // dropTime, duration
                orders.push_back(make_tuple(dropTime + du, FILLED, dropTime - dt + du));
                push_heap(orders.begin(), orders.end(), comp);
                totalRemote += dropTime -dt + du;
                ++numRemote;
            } else {
                ++t;
            }
        }
    }

    // cout << "numStore = " << numStore << ", numRemote = " << numRemote << endl;
    cout << setprecision(6) << fixed;
    if (numStore == 0) cout << 0 << " ";
    else cout << (totalStore / numStore) << " ";

    if (numRemote == 0) cout << 0;
    else cout << (totalRemote / numRemote);

    return 0;
}
