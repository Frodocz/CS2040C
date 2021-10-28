#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, N, p;
    cin >> X >> N;

    int remain = X;

    for (int i = 0; i < N; ++i) {
        cin >> p;
        remain += X - p;
    }
    
    cout << remain;

    return 0;
}