#include <iostream>
#include <vector>

using namespace std;

class UnionFind { // OOP style
private:
    vector<int> p, rank, setSize; // vector<int> p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        // setSize.assign(N, 1);                        // optional feature
        // numSets = N;                                 // optional feature
    };
    // ~UnionFind() {};

    int findSetIter(int i) { // --> 0.28s
        int tmp = i;
        while (p[i] != i) {
            i = p[i];
        }
        p[tmp] = i;
        return i;
    }

    int findSet(int i) { return (i == p[i]) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        // int x = findSetIter(i), y = findSetIter(j);
        if (rank[x] > rank[y]) swap(x, y); // keep x shorter than y
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        // setSize[y] += setSize[x];
        --numSets;
    }

    // int numDisjointSets() { return numSets; } // optional
    // int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    UnionFind u(n);
    while (q--) {
        char op; int i, j;
        cin >> op >> i >> j;
        if (op == '?') {
            cout << (u.isSameSet(i, j) ? "yes\n" : "no\n");
        } else {
            u.unionSet(i, j);
        }
    }

    return 0;
}
