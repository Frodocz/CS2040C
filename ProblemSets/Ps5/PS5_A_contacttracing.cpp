#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

bool isOverlap(pair<ll, ll> &t1, pair<ll, ll> &t2) {
    auto [l1, r1] = t1; auto [l2, r2] = t2;
    return !(r1 < l2 || r2 < l1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, D; cin >> N >> D;
    ll C; cin >> C;

    vector<ii> people;
    set<ll> infected;

    for (int i = 0; i < C; ++i) {
        ll idx; cin >> idx;
        infected.insert(idx - 1);
    }

    for (int i = 0; i < N; ++i) {
        ll s, t; cin >> s >> t;
        people.emplace_back(s, t);
    }

//    cout << "People: \n";
//    for (int i = 1; i <= N; ++i) {
//        cout << i << " -> [" << people[i - 1].first << ", " << people[i - 1].second << "]\n";
//    }
//    cout << "\n";
//
//    cout << "infected: ";
//    for (auto i : infected) {
//        cout << i << " ";
//    }
//    cout << endl;

    // current infected
    // int day = 1;
    while (D--) {
        // Check the next day infected people
        vector<ll> newlyInfected;
        for (int i = 0; i < N; ++i) {
            if (infected.find(i) == infected.end()) {
                for (auto p : infected) {
                    if (isOverlap(people[p], people[i])) { // newly infected i
                        newlyInfected.push_back(i);
                        break;
                    }
                }
            }
        }
        // cout << "After day " << day << ", people affected : ";
        for (auto i : newlyInfected) {
            // cout << (i + 1) << " ";
            infected.insert(i);
        }
        // cout << endl;
    }

    for (auto p : infected) {
        cout << (p + 1 )<< " ";
    }
    cout << "\n";

    return 0;
}
