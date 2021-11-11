#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, string> player;

bool comp(const player &p1, const player &p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    player players1[N], players2[N], players3[N];
    unordered_set<string> names;

    string name; ll s1, s2, s3;
    for (int i = 0; i < N; ++i) {
        cin >> name >> s1 >> s2 >> s3;
        players1[i] = {s1, name};
        players2[i] = {s2, name};
        players3[i] = {s3, name};
        names.insert(name);
    }

    sort(players1, players1 + N, comp);
    sort(players2, players2 + N, comp);
    sort(players3, players3 + N, comp);

    int c1 = 0, c2 = 0, c3 = 0;
    while (c1 < N && c2 < N && c3 < N) {
        while (c1 < N && names.find(players1[c1].second) == names.end()) { ++c1; }
        if (c1 == N) break; names.erase(players1[c1].second);
        while (c2 < N && names.find(players2[c2].second) == names.end()) { ++c2; }
        if (c2 == N) break; names.erase(players2[c2].second);
        while (c3 < N && names.find(players3[c3].second) == names.end()) { ++c3; }
        if (c3 == N) break; names.erase(players3[c3].second);
        vector<string> s;
        s.push_back(players1[c1].second);
        s.push_back(players2[c2].second);
        s.push_back(players3[c3].second);
        sort(s.begin(), s.end());
        cout << s[0] << " " << s[1] << " " << s[2] << "\n";
    }
    return 0;
}
