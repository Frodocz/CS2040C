#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    int cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        s.push(cur);
    }

    while (!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }

    return 0;
}