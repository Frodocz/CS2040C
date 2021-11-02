#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // num of input variables
    cin >> n;

    unordered_map<char, char> um;
    for (int i = 0; i < n; ++i) {
        char b;
        cin >> b;
        um['A' + i] = (b == 'T');
    }

    char cur;
    stack<char> s;
    while (cin >> cur) {
        if (cur >= 'A' && cur <= 'Z') {
            s.push(um[cur]);
        } else if (cur == '-') {
            bool b = s.top();
            s.pop();
            s.push(!b);
        } else {
            bool a = s.top();
            s.pop();
            bool b = s.top();
            s.pop();
            if (cur == '*') {
                s.push(a && b);
            } else {
                s.push(a || b);
            }
        }
    }

    cout << (s.top() ? 'T' : 'F');
    return 0;
}
