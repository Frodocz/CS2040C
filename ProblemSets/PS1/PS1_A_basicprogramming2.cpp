#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    unordered_set<int> us;
    unordered_map<int, int> um;
    vector<int> nums;

    bool isUnique = true, is7777 = false;
    int valMoreThanHalf = -1;


    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    switch (t) {
        case 1:
            for (const int i : nums) {
                if (us.find(7777 - i) != us.end()) {
                    is7777 = true;
                    break;
                } else {
                    us.insert(i);
                }
            }
            if (is7777) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            break;

        case 2:
            for (const int i : nums) {
                if (us.find(i) != us.end()) {
                    isUnique = false;
                    break;
                } else {
                    us.insert(i);
                }
            }
            if (isUnique) {
                cout << "Unique";
            } else {
                cout << "Contains duplicate";
            }
            break;

        case 3:
            for (const int i : nums) {
                if (um.find(i) != um.end()) {
                    int appear = ++um[i];
                    if (appear > n / 2) {
                        valMoreThanHalf = i;
                        break;
                    }

                } else {
                    um[i] = 1;
                }
            }
            cout << valMoreThanHalf;
            break;

        case 4:
            sort(nums.begin(), nums.end());
            if (n % 2 == 0) {
                cout << nums[n / 2 - 1] << " " << nums[n / 2];
            } else {
                cout << nums[n / 2];
            }
            break;

        case 5:
            sort(nums.begin(), nums.end());

            auto start = lower_bound(nums.begin(), nums.end(), 100), end = upper_bound(nums.begin(), nums.end(), 999);
            while (start != end) {
                cout << *start++ << " ";
            }
            break;

    }

    return 0;
}
