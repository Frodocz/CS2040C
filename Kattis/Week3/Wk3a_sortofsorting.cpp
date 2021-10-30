#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isLessThan(string name1, string name2) {
    if (name1[0] < name2[0]) return true;
    else if (name1[0] > name2[0]) return false;
    else return name1[1] < name2[1];
//    string sub1 = name1.substr(0, 2);
//    string sub2 = name2.substr(0, 2);
//    return sub1 < sub2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string name;

    while (cin >> n && n != 0) {
        vector<string> names;
        while (n--) {
            cin >> name;
            names.push_back(name);
        }
        stable_sort(names.begin(), names.end(), isLessThan);
        for (const auto x : names) {
            cout << x << "\n";
        }
        cout << "\n";
    }

    return 0;
}
