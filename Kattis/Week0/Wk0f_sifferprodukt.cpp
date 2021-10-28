#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num = 1;
    cin >> n;

    while (n > 9) {
        num = 1;
        while (n > 0) {
            int rem = n % 10;
            n /= 10;
            if (rem != 0) num *= rem;
        }
        n = num;
    }
    cout << n;
    return 0;
}