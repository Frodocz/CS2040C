#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &a) {
    int n = a.size(), cnt = 0;
    for (int i = 1; i < n; ++i) {
        int j = i - 1, tmp = a[i];
        for (; j >= 0 && a[j] > tmp; --j) {
            a[j + 1] = a[j];
            ++cnt;
        }
        a[j + 1] = tmp;
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, dataset;
    cin >> n;

    while (n--) {
        cin >> dataset;

        vector<int> a(20);
        int h;
        for (int i = 0; i < 20; i++) {
            cin >> h;
            a[i] = h;
        }
        cout << dataset << " ";
        insertionSort(a);
    }

    return 0;
}
