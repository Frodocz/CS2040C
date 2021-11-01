#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string cmd;
    deque<int> dq1, dq2;

    cin >> n;
    while (n--) {
        int val;
        cin >> cmd >> val;
        if (cmd == "push_back") {//push_back
            dq2.push_back(val);
            if (dq2.size() > dq1.size()) {
                dq1.push_back(dq2[0]);
                dq2.pop_front();
            }
        } else if (cmd == "push_front") {
            dq1.push_front(val);
            if (dq1.size() > dq2.size() + 1) {
                dq2.push_front(dq1[dq1.size() - 1]);
                dq1.pop_back();
            }
        } else if (cmd == "push_middle") {
            if (dq1.size() > dq2.size()) {
                dq2.push_front(val);
            } else {
                dq1.push_back(val);
            }
        } else if (cmd == "get") {
            if (val < dq1.size()) {
                cout << dq1[val] << "\n";
            } else {
                cout << dq2[val - dq1.size()] << "\n";
            }
        }
    }

    return 0;
}
