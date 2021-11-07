#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll, char> TL; // {time drop off, location}
typedef pair<TL, ll> pres; // {{time drop off, location}, time taken}
typedef pair<ll, ll> tech; // {id, time finish}

// Not AC, need to find out why
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t; cin >> n >> t;

    ll numStore = 0, numRemote = 0;
    double totalStore = 0, totalRemote = 0;

    auto comp = [](pres &a, pres &b) {
        if (a.first.first != b.first.first) { // smaller drop time higher
            return a.first.second > b.first.second;
        } else {
            if (a.first.second != b.first.second) { // 'R' and 'S', store > remote
                return a.first.first > b.first.first;
            } else {
                return a.second > b.second;
            }
        }
    };

    auto compTech = [](tech &a, tech &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    };

    priority_queue<pres, vector<pres>, decltype(comp)> pqStore(comp), pqRemote(comp); // {{time drop off, location}, time taken}
    priority_queue<tech, vector<tech>, decltype(compTech)> techs(compTech); // {id, time finish}

    while (n--) {
        ll d; char c; ll k; cin >> d >> c >> k; // d --> drop time
        if (c == 'S') {
            pqStore.push({{d, c}, k}); // push the prescription
        } else {
            pqRemote.push({{d, c}, k});

        }
    }

    ll curTime = 0, techAvailable = t;
    while (!pqStore.empty() || !pqRemote.empty()) {
        pres pre;
        bool highestInStore = false;
        if (pqStore.empty() || pqStore.top().first.first > curTime) {
            pre = pqRemote.top();
        } else {
            highestInStore = true;
            pre = pqStore.top(); // { {drop time, location}, timeCost }
        }
        auto dropTime = pre.first.first, timeCost = pre.second;

        if (techAvailable > 0) {
            curTime = dropTime;
            if (highestInStore) pqStore.pop();
            else pqRemote.pop();
            techs.push({t - techAvailable, dropTime + timeCost});
            --techAvailable;
            if (pre.first.second == 'S') {
                ++numStore;
                totalStore += timeCost;
                // cout << "totalStore = " << totalStore << ", dropTime = " << dropTime << ", curTime = " << curTime << ", timeCost = " << timeCost << endl;
            } else {
                ++numRemote;
                totalRemote += timeCost;
                // cout << "totalRemote = " << totalRemote << ", dropTime = " << dropTime << ", curTime = " << curTime << ", timeCost = " << timeCost << endl;

            }
        } else if (techs.top().second > curTime) {
            // cout << "Check the first tech, his finish time = " << techs.top().second << ", curTime = " << curTime << endl;
            ++curTime;
        } else {
            if (highestInStore) pqStore.pop();
            else pqRemote.pop();
            auto te = techs.top(); // get the first available technician
            techs.pop(); // activate the technician
            techs.push({te.first, curTime + timeCost});
            if (pre.first.second == 'S') {
                ++numStore;
                totalStore += curTime + timeCost - dropTime;
                // cout << "totalStore = " << totalStore << ", dropTime = " << dropTime << ", curTime = " << curTime << ", timeCost = " << timeCost << endl;
            } else {
                ++numRemote;
                totalRemote += curTime + timeCost - dropTime;
                // cout << "totalRemote = " << totalRemote << ", dropTime = " << dropTime << ", curTime = " << curTime << ", timeCost = " << timeCost << endl;
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
