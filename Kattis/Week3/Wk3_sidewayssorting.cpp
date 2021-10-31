#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool insensitive(string left, string right) {
    for (int i = 0 ; i < left.size(); i++) {
        if (tolower(left[i]) < tolower(right[i])) {
            return true;
        }
        else if (tolower(left[i]) > tolower(right[i])) {
            return false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    while (cin >> r >> c && r != 0) {
        vector<string> grid(r);
        for(int i = 0; i < r; i++) {
            cin >> grid[i];
        }
        vector<string> rotated(c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                rotated[j] += grid[i][j];
            }
        }

        sort(rotated.begin(), rotated.end(), insensitive);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = rotated[j][i];
            }
        }

        for (auto line : grid) {
            cout << line << "\n";
        }
        cout << "\n";
    }
    return 0;
}
