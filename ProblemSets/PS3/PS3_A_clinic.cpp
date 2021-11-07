#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<string, ll> patient;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Process a patient arrival to the clinic.
    // The patient will have an arrival time T, a name M, and a severity S that is accessed automatically by scanners at the entrance.

    // 2. At time T, treat patient of highest priority: by S + K * W -- > S: severity, K: constant, W: waiting time; by lexicographic

    // 3. Check existance of patient name M, then remove the patient

    unordered_set<string> clinic;

    ll N, K; cin >> N >> K;

    auto comp = [K](patient &a, patient &b) { // patient --> {name, {time, severity}}
        if (a.second != b.second) return a.second < b.second;
        else return a.first > b.first;
    };

    priority_queue<patient, vector<patient>, decltype(comp)> pq(comp);

    while (N--) {
        ll Q, T; cin >> Q >> T;
        if (Q == 1) {
            string M; ll S; cin >> M >> S;
            clinic.insert(M);
            pq.push({M, S - K * T});
        } else if (Q == 2) {
            // output name
            // if empty, doctor takes a break
            if (clinic.empty()) {
                cout << "doctor takes a break" << "\n";
                continue;
            }
            while (!pq.empty()) {
                auto p = pq.top(); pq.pop();
                if (clinic.count(p.first)) {
                    cout << p.first<< "\n";
                    clinic.erase(p.first);
                    break;
                }
            }
        } else {
            string M; cin >> M;
            if (clinic.find(M) != clinic.end()) {
                clinic.erase(M);
            }
            if (clinic.empty()) cout << "doctor takes a break" << "\n";
        }
    }

    return 0;
}
