#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T, P, R, F;
    cin >> T;

    while (T--) {
        cin >> P >> R >> F;

        int cnt = 0;
        F /= P;
        while (F > 0) {
            F /= R;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}