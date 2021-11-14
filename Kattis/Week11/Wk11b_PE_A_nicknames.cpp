#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A;

    string s;
    set<string> names; set<string> nickNames;
    while (A--) {
        cin >> s;
        names.insert(s);
    }

    cin >> B;
    while (B--) {
        cin >> s;
        char curr = s[0], next = (char)(s[0] + 1);
        string first(1, curr), last(1, next);
        // cout << "substring = " << s.substr(0, 1) << endl;
        auto begin = names.lower_bound(first);
        auto end = names.upper_bound(last);
        auto it = begin;
        long long cnt = 0;
        // cout << "current nickname = " << s << endl;
        while (it != end) {
            string name = *it++;
            // cout << "current name = " << name << ", ";
            if (s == name.substr(0, s.size())) {
                // cout << s << " is prefix of " << name << endl;
                ++cnt;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
