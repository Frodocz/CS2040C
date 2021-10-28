#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t;
    cin >> N >> t;

    if (t == 1) {
        cout << 7;
        return 0;
    }

    vector<int> A;
    int m1, m2;
    ll sum = 0;
    string s;

    switch (t) {
        case 2:
            cin >> m1 >> m2;
            if (m1 > m2)
                cout << "Bigger" << endl;
            else if (m1 == m2)
                cout << "Equal" << endl;
            else
                cout << "Smaller" << endl;
            break;

        case 3:
            for (int i = 0; i < 3; ++i) {
                cin >> m1;
                A.push_back(m1);
            }
            sort(A.begin(), A.end());
            cout << A[1];
            break;

        case 4:
            while (N--) {
                cin >> m1;
                sum += m1;
            }
            cout << sum;
            break;

        case 5:
            while (N--) {
                cin >> m1;
                if (m1 % 2 == 0)
                    sum += m1;
            }
            cout << sum;
            break;

        case 6:
            while (N--) {
                cin >> m1;
                char c = 'a' + (m1 % 26);
                s += c;
            }
            cout << s;
            break;

        case 7:
            vector<bool> visited(N, false);
            for (int i = 0; i < N; ++i) {
                cin >> m1;
                A.push_back(m1);
            }
            int i = 0;
            while (true) {
                if (i >= N) {
                    cout << "Out" << endl;
                    break;
                } else if (visited[i]) {
                    cout << "Cyclic" << endl;
                    break;
                } else if (i == N - 1) {
                    cout << "Done" << endl;
                    break;
                } else {
                    visited[i] = true;
                    i = A[i];
                }
            }
            break;

    }
    return 0;
}