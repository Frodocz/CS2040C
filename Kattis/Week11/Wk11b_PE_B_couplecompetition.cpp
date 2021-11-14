#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

ll jump(ll src, ll dest, bool toLeft, vector<ll> &blocks) {
    ll ans = 0;
    ll cur = src;
    while (cur != dest) {
        if (toLeft) {
            if (blocks[cur] > blocks[cur - 1]) return -1;
            else {
                ++ans;
                --cur;
            }
        } else {
            if (blocks[cur] > blocks[cur + 1]) return -1;
            else {
                ++ans;
                ++cur;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N; cin >> N;

    vector<ll> blocks;
    ll maxHeight = -1;
    set<ll> highestIdx;

    for (int i = 0; i < N; ++i) {
        ll h; cin >> h;
        if (h > maxHeight) {
            maxHeight = h;
            highestIdx.clear();
            highestIdx.insert(i);
        } else if (h == maxHeight) {
            highestIdx.insert(i);
        }
        blocks.push_back(h);
    }

//    cout << "blocks: ";
//    for (auto c : blocks) cout << c << " ";
//    cout << "\n";
//
//    cout << "highest index of height " << maxHeight << " : ";
//    for (auto c : highestIdx) cout << c << " ";
//    cout << "\n";

    for (ll i = 0; i < N; ++i) {
        if (highestIdx.count(i)) cout << "0\n";
        else {
            ll left = 0, right = N - 1;
            for (auto idx : highestIdx) {
                if (idx < i) left = idx;
                else {
                    right = idx;
                    break;
                }
            }
            // cout << left << ", " << right << endl;
            if (left == right) {
                cout << jump(i, left, true, blocks) << "\n";
            } else if (blocks[left] != maxHeight) {
                cout << jump(i, right, false, blocks) << "\n";
            } else if (blocks[right] != maxHeight) {
                cout << jump(i, left, true, blocks) << "\n";
            } else {
                ll lAns = jump(i, left, true, blocks);
                ll rAns = jump(i, right, false, blocks);
                if (rAns == -1) cout << lAns << "\n";
                else if (lAns == -1) cout << rAns << "\n";
                else cout << min(lAns, rAns) << "\n";
            }
        }
    }

    return 0;
}
