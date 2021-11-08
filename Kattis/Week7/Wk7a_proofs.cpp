#include <iostream>
#include <unordered_set>

using namespace std;
typedef long long ll;

bool validateLine(const string &s, unordered_set<string> &assumptions) {
    // line = [A B C D E -> F];
    if (s[0] == '-') {
        assumptions.insert(s.substr(3));
        return true;
    } else {
        auto pos = s.find("->");
        string as = s.substr(0, pos);
        string a;
        for (auto c : as) {
            if (c != ' ') a += c;
            else {
                if (assumptions.find(a) == assumptions.end()) {
                    return false;
                }
                assumptions.insert(a);
                a.clear();
            }
        }
        assumptions.insert(s.substr(pos + 3));
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n; cin.ignore();
    unordered_set<string> assumptions;
    for (ll i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        if (!validateLine(line, assumptions)) {
            cout << i + 1;
            return 0;
        }
    }
    cout << "correct";

    return 0;
}
