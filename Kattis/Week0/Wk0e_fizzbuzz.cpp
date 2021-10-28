#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % x == 0) {
            cout << "Fizz";
            if (i % y == 0) cout << "Buzz";
        } else {
            if (i % y == 0) cout << "Buzz";
            else cout << i;
        }
        cout << "\n";
    }
    return 0;
}