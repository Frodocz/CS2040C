#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); // clear the \n from the input buffer before using getline

    string s;
    list<char> l;
    while (n--) {
        getline(cin, s);
        auto it = l.end();
        for (char c : s) {
            if (c == '[') {
                it = l.begin();
            } else if (c == ']') {
                it = l.end();
            } else if (c == '<') {
                auto tmp = it;
                --tmp;
                if (tmp == --l.begin()) continue;
                l.erase(tmp);
            } else {
                l.insert(it, c);
            }
        }
        // cout << "l size -> " << l.size() << endl;

        for (auto c : l) {
            cout << c;
        }
        cout << "\n";
        l.clear();
    }

    return 0;
}
