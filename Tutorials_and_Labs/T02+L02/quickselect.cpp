#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int partition(vector<int> &a, int l, int r, int pivotIdx) {
    int pivotVal = a[pivotIdx];
    swap(a[l], a[pivotIdx]);
    int m = l;
    for (int i = l + 1; i < r; ++i) {
        if (a[i] < pivotVal) {
            ++m;
            swap(a[m], a[i]);
        }
    }
    swap(a[m], a[l]);
    return m;
}

int quickSelect(vector<int> &a, int l, int r, int k){
    while (l < r) {
        int pivotIdx = rand() % (r - l) + l;
        pivotIdx = partition(a, l, r, pivotIdx);
        if (k == pivotIdx) return a[k];
        else if (k < pivotIdx) r = pivotIdx - 1;
        else l = pivotIdx + 1;
    }
    return a[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a{7, 3, 9, 5, 0, 11, 10};
    srand(time(NULL));

    cout << "item at index 3 = " << quickSelect(a, 0, a.size(), 3) << endl;
    for (auto c : a) {
        cout << c << " ";
    }
    cout << endl;

    vector<int> b{7, 3, 9, 5, 0, 11, 10};
    auto it = b.begin() + 3; // element at index 3
    nth_element(b.begin(), it, b.end());
    cout << "nth_element = " << *it <<endl;

    return 0;
}
