#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string slat; // TBLR
    int cntTB = 0, cntLR = 0;
    for (int i = 0; i < n; i++) {
        cin >> slat;
        if (slat[0] == '0') cntTB++;
        if (slat[1] == '0') cntTB++;
        if (slat[2] == '0') cntLR++;
        if (slat[3] == '0') cntLR++;
    }
    
    int total = min(cntTB / 2, cntLR / 2);
    cout << total << " " << cntTB - 2 * total << " " << cntLR - 2 * total << endl;

    return 0;
}