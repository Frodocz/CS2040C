#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    vector<int> a;
    while (cin >> i) {
        a.push_back(i);
    }

    for (int i = 0; i < 5; ++i) {
        bool swapped = false;
        for (int j = 1; j < 5 - i; ++j) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                swapped = true;
                printVector(a);
            }
        }
        if (!swapped) break;
    }
    return 0;
}
