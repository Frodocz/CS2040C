#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a, b, c;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        if ((a + b == c) || (a * b == c) || (a - b == c) || (b - a == c) || (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c)) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}