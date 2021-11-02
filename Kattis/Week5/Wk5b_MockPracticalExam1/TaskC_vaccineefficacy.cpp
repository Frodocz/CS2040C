#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define NUM_STRAIN 3

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string s;
    int numVaccined = 0, numPlacebo = 0;
    vector<int> numInfected1(3); // for vaccined
    vector<int> numInfected2(3); // for placebo
    while (n--) {
        cin >> s;

        if (s[0] == 'Y') { // vaccined
            ++numVaccined;
            for (int i = 0; i < NUM_STRAIN; ++i) {
                if (s[i + 1] == 'Y')
                    ++numInfected1[i];
            }
        } else { // placebo
            ++numPlacebo;
            for (int i = 0; i < NUM_STRAIN; ++i) {
                if (s[i + 1] == 'Y')
                    ++numInfected2[i];
            }
        }
    }

    for (int i = 0; i < NUM_STRAIN; ++i) {
        double infectRate1 = (double)numInfected1[i] / (double)numVaccined;
        double infectRate2 = (double)numInfected2[i] / (double)numPlacebo;
        if (infectRate1 >= infectRate2) {
            cout << "Not Effective" << "\n";
        } else {
            double efficacy = (infectRate2 - infectRate1) / infectRate2 * 100;
            cout << setprecision(6) << efficacy << "\n";
        }
    }

    return 0;
}
