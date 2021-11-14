#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pos;

//To store matrix cell coordinates
struct Point {
    int x;
    int y;
};

// A Data Structure for queue used in BFS
struct QueueNode {
    Point p; // The coordinates of a cell
    int dist; // cell's distance of from the source
};

// check whether given cell (row, col) is a valid cell or not.
bool isValid(int row, int col, int R, int C) {
    // return true if row number and column number is in range
    return (row >= 0) && (row < R) && (col >= 0) && (col < C);
}

// These arrays are used to get row and column numbers of 8 neighbours of a given cell
int rowNum[] = {2, 2, -2, -2, 1, 1, -1, -1};
int colNum[] = {1, -1, 1, -1, 2, -2, 2, -2};

// function to find the shortest path between a given source cell to a destination cell.
int bfs(vector<vector<char>> &maze, Point src, Point dest) {
    int N = maze.size();
    vector<vector<bool>> visited(N, vector<bool>(N));
    // Mark the source cell as visited
    visited[src.x][src.y] = true;
    // Create a queue for BFS
    queue<QueueNode> q;
    // Distance of source cell is 0
    QueueNode s = {src, 0};
    q.push(s);  // Enqueue source cell

    // BFS starting from source cell
    while (!q.empty()) {
        QueueNode curr = q.front();
        Point pt = curr.p;
        // If we have reached the destination cell, we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        // Otherwise dequeue the front cell in the queue and enqueue its adjacent cells
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            // if adjacent cell is valid, has path and not visited yet, enqueue it.
            if (isValid(row, col, N, N) && maze[row][col] != '#' && !visited[row][col]) {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                QueueNode adjCell = { {row, col},curr.dist + 1 };
                q.push(adjCell);
            }
        }
    }

    // Return -1 if destination cannot be reached
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;

    vector<vector<char>> maze(n, vector<char>(n));
    Point knight;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
            // cout << maze[i][j] << " ";
            if (maze[i][j] == 'K') {
                knight.x = i;
                knight.y = j;
            }
        }
        // cout << "\n";
    }

    // cout << "Knight at (" << knight.first << ", " << knight.second << ")" << endl;
    Point dest = {0, 0};
    cout << bfs(maze, knight, dest);
    return 0;
}
