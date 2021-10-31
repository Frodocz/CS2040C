#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Initialize game and note down
//    1.1 the Cells belong to each faculty
//    1.2 the students belong to each faculty
//    1.3 sort the students by id, then find the distance this student to its corresponding cell
//    1.4 sort the distances so that we just need to make least v steps with at least T students
// 2. Sort the final distances so that we meet the requirement by at least G faculties

struct Student {
    int id;
    int faculty;
    pair<int, int> cell;
    Student(int i, int f, int x, int y) : id(i), faculty(f), cell({x, y}) {};
};

struct Faculty {
    int id;
    int T;
    vector<pair<int, int>> cells;
    vector<Student> students;
    vector<long long> distances;
    Faculty(int i): id(i), T(0) {};

    void setT(const int t) { T = t; };

    void sortStudents() {
        sort(students.begin(), students.end(), [](const Student &s1, const Student &s2) {return s1.id < s2.id;});
    }

    void sortCells() {
        sort(cells.begin(), cells.end());
    }

    void sortDistances() {
        sort(distances.begin(), distances.end());
    }

    void toString() {
        cout << "Faculty " << id + 1 << " (T = " << T << "):\n"
             << "Cells: [ ";
        for (auto c : cells) {
            cout << "(" << c.first << ", " << c.second << ") ";
        }
        cout << "]\n";
        cout << "Students: [ ";
        for (auto s : students) {
            cout << "Student " << s.id << " at (" << s.cell.first << ", " << s.cell.second << ") ";
        }
        cout << "]\n";
        cout << "Distances: [ ";
        for (auto d : distances) {
            cout << d << " ";
        }
        cout << "]\n";
    }
};

// At least G faculty meet their compliance target
// A compliance target is met if there is at least T students found in their assigned cells.
// Every faculty has an assigned T value.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, F, S, G;
    cin >> R >> C >> F >> S >> G; // row, col, faculty number, student number, minimun faculty number

    vector<Faculty> faculties;
    for (int i = 0; i < F; ++i) { // get cells belongs to each faculty
        Faculty f(i);
        int numCells; cin >> numCells;
        for (int j = 0; j < numCells; ++j) {
            int x, y; cin >> x >> y;
            f.cells.push_back({x, y});
        }
        f.sortCells();
        faculties.push_back(f);
    }

    for (int i = 0; i < S; ++i) {
        int x, y, id, fac;
        cin >> x >> y >> id >> fac;
        Student s(id, fac - 1, x, y);
        faculties[fac - 1].students.push_back(s);
    }

    for (auto &f : faculties) {
        int t; cin >> t;
        f.setT(t);

        int j = 0;
        f.sortStudents();
        for (const auto &s : f.students) {
            int startX = s.cell.first, startY = s.cell.second;
            int endX = f.cells[j].first, endY = f.cells[j].second;
            ++j;
            long long dist = abs(startX - endX) + abs(startY - endY);
            f.distances.push_back(dist);
        }
    }

    vector<long long> res;
    for (auto &f : faculties) {
        long long dist = 0;
        f.sortDistances();
        for (int i = 0; i < f.T; ++i) {
            dist += f.distances[i];
        }
        res.push_back(dist);
    }

    sort(res.begin(), res.end());

    long long  moves = 0;
    for (int i = 0; i < G; ++i) {
        moves += res[i];
    }
    cout << moves;
    return 0;
}
