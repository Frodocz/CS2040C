#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a == 0 || b == 0 || c == 0 || n < 3 || (a + b + c) < n) 
        cout << "NO";
    else 
        cout << "YES";

    return 0;
}