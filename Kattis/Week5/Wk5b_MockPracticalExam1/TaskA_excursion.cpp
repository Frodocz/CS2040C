#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<ll> count(3, 0);

    for (auto c : s) {
        ++count[c - '0'];
    }

    ll cnt = 0;

    for (auto c : s) { // all 0s should be moved to front, so swap with every different val
        if (c == '0') {
            --count[0];
        } else {
            cnt += count[0];
        }
    }

    for (auto c : s) {
        if (c == '1') {
            --count[1];
        } else if (c == '2') { // all 2s should be moved to back
            cnt += count[1];
        }
    }

    cout << cnt;
    return 0;
}
