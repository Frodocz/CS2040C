#include <iostream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

using s_size = string::size_type;

int process_ranged_string(const string &s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum = 0;

    s_size tmpStart = 0, tmpEnd = 0;
    tmpEnd = s.find_first_of("-");
    if (tmpEnd == string::npos) {
        sum = 1;
    } else {
        istringstream is1(s.substr(tmpStart, tmpEnd));
        int left, right;
        is1 >> left;

        istringstream is2(s.substr(tmpEnd + 1));
        is2 >> right;
        sum = right - left + 1;
    }
//    cout << "sum = " << sum << endl;
    return sum;
}

int main() {
    string str;
    getline(cin, str);

//    cout << str << endl; // 1-3;5;7;10-13

    s_size tStart = 0, tEnd = 0; // str[tStart, tEnd]
    tEnd = str.find_first_of(";");
    s_size sum = 0;
    while (tEnd != string::npos) {
        string cur = str.substr(tStart, tEnd - tStart);

        sum += process_ranged_string(cur);

        tStart = tEnd + 1;
        tEnd = str.find_first_of(";", tStart);
    }

    if (tStart < str.size()) {
//        cout << str.substr(tStart) << endl;
        sum += process_ranged_string(str.substr(tStart));
    }

    cout << sum << endl;
    return 0;
}