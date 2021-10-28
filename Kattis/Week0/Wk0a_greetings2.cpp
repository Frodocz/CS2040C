#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    string sub = s.substr(1, s.size() - 2);

    cout << "h" + sub + sub + "y";

    return 0;
}