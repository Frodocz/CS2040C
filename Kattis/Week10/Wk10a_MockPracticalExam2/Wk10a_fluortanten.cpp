#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> line(n);
    ll sum = 0;

    ll curCnt = 0;
    while (curCnt < n - 1) {
        ll cur; cin >> cur;
        if (cur == 0) continue;
        line[curCnt++] = cur;
        sum += cur * curCnt;
    }
    ll maxSum = sum;
    // backward search
    for (ll i = n - 1; i > 0; --i) {
        // sum -= line[i - 1] * i; // get the sum before the current idx
        // ll newSum = sum + line[i - 1] * (i + 1); // get the new sum
        ll newSum = sum + line[i - 1]; // simplify
        if (newSum > maxSum) maxSum = newSum;
        sum = newSum;
    }

    cout << maxSum;
    return 0;
}
