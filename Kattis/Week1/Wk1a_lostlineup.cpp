#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> line(n, 1);
    int cur;
    for (int i = 2; i <= n; i++) {
        cin >> cur;
        line[cur + 1] = i;
    }

    for (auto i : line) {
    	cout << i << " ";
    }
    cout << endl;

    return 0;
}