#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    for (int i = 0; i < s.size(); ) {
        if (s[i] == ':' or s[i] == ';') {
            // process
            if (i + 1 < s.size() && s[i + 1] == ')') {
                cout << i << "\n";
                ++i;
            } else if (i + 2 < s.size() && s[i + 1] == '-' && s[i + 2] == ')') {
                cout << i << "\n";
                i += 2;
            } else {
                ++i;
            }
        } else {
            ++i;
        }
    }
    return 0;
}
