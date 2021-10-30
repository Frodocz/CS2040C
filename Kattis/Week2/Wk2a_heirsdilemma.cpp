#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(int n) {
	int tmp = n;
	vector<bool> cnt(10, false);
	while (n > 0) {
		if (n % 10 == 0) return false;
		if (tmp % (n % 10) != 0) return false;
		if (cnt[n % 10]) return false;
		cnt[n % 10] = true;
		n /= 10;
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lo, hi;
    cin >> lo >> hi;

    int cnt = 0;

    for (int i = lo; i <= hi; ++i) {
        if (isValid(i)) {
            ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}