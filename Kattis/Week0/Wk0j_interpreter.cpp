#include <iostream>
#include <vector>

using namespace std;

#define MEMORY_SIZE     1000
#define REGISTER_NUM    10

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, cnt = 0, idx = 0;
    vector<int> registers(REGISTER_NUM), ram(MEMORY_SIZE);

    while (cin >> i) {
        ram[idx++] = i;
    }

    idx = 0;
    while (true) {
        ++cnt;
        i = ram[idx];
        int op = i / 100, a = (i / 10) % 10, b = i % 10;
        if (op == 1) {
            break;
        } else if (op == 2) {
            registers[a] = b;
        } else if (op == 3) {
            registers[a] = (registers[a] + b) % 1000;
        } else if (op == 4) {
            registers[a] = (registers[a] * b) % 1000;
        } else if (op == 5) {
            registers[a] = registers[b];
        } else if (op == 6) {
            registers[a] = (registers[a] + registers[b]) % 1000;
        } else if (op == 7) {
            registers[a] = (registers[a] * registers[b]) % 1000;
        } else if (op == 8) {
            registers[a] = ram[registers[b]];
        } else if (i / 100 == 9) {
            ram[registers[b]] = registers[a];
        } else {
            if (registers[b] != 0) {
                idx = registers[a];
                continue;
            }
        }
        ++idx;
    }

    cout << cnt << endl;
    return 0;
}