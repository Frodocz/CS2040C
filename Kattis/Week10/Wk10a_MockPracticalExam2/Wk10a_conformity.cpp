#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef set<int> si;
typedef map<si, int> ssi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ssi counts;
    int popular = 0, max = 0;

    while (n--) {
        si c;
        for (int i = 0; i < 5; ++i) {
            int course; cin >> course;
            c.insert(course);
        }
        if (counts.find(c) != counts.end()) {
            ++counts[c];
        } else {
            counts[c] = 1;
        }

        if (counts[c] > max) {
            max = counts[c];
            popular = counts[c];
        } else if (counts[c] == max) {
            popular += counts[c];
        }
    }

    cout << popular << endl;
    return 0;
}
