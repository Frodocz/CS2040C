#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string name, prev;

    cin >> n;

    cin >> name;
    prev = name;

    bool isIncreasing = false;
    bool isDecreasing = false;
    bool isNeither = false;

    for (int i = 0; i < n - 1; ++i) {
        cin >> name;
        if (name < prev) {
            if (isIncreasing) {
                isNeither = true;
                break;
            }
            if (!isDecreasing) {
                isDecreasing = true;
            }
        } else {
            if (isDecreasing) {
                isNeither = true;
                break;
            }
            if (!isIncreasing) {
                isIncreasing = true;
            }
        }
        prev = name;
    }
    if (isNeither) cout << "NEITHER";
    else if (isIncreasing) cout << "INCREASING";
    else cout << "DECREASING";

    return 0;
}
