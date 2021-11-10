#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> names;
    map<string, pair<string, int>> table;
    int N; cin >> N;

    string name, birthday; int like;
    while (N--) {
        cin >> name >> like >> birthday;
        if (table.find(birthday) != table.end()) {
            if (table[birthday].second < like) {
                names.erase(table[birthday].first);
                names.insert(name);
                table[birthday] = {name, like};
            }
        } else {
            table.insert({birthday, {name, like}});
            names.insert(name);
        }
    }

    cout << names.size() << "\n";
    for (auto name : names) {
        cout << name << "\n";
    }

    return 0;
}
