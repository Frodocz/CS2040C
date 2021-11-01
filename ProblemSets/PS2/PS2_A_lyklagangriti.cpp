#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pwd;
    cin >> pwd;
    if (pwd.find_first_of("LRB") == string::npos) {
        cout << pwd;
        return 0;
    }

    list<char> l;

    auto it = l.end();
    for (const auto c : pwd) {
        // cout << "print c = " << c << endl;
        if (c == 'L') {
            --it;
        } else if (c == 'R') {
            ++it;
        } else if (c == 'B') {
            auto tmp = it;
            --tmp;
            l.erase(tmp);
        } else {
            l.insert(it, c);
        }
    }

    for (auto c : l) {
        cout << c;
    }

    return 0;
}
