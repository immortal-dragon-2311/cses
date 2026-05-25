#include <iostream>
#include <string>

using namespace std;

bool vis[9][9];
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int p[49];

int tryPath(int idx, int r, int c) {
    // checking if the grid is split
    // 1. right and left blocked, but not top and bottom
    // 2. top and bottom are blocked, but not left and right

    if ((
        vis[r][c-1] && vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]
    ) || (
        !vis[r][c-1] && !vis[r][c+1] && vis[r-1][c] && vis[r+1][c]
    )) {
        return 0;
    }

    if (r == 7 && c == 1) {
        if (idx == 48) {
            return 1;
        }
        return 0;
    }

    if (idx == 48) {
        return 0;
    }

    vis[r][c] = true;
    int ret = 0;

    // dead-end pruning: if any unvisited non-destination neighbor is now isolated, prune
    for (int i = 0; i < 4; i++) {
        int nr = r + mv[i][0], nc = c + mv[i][1];
        if (vis[nr][nc]) continue;
        if (nr == 7 && nc == 1) continue;
        int freeNeighbors = 0;
        for (int j = 0; j < 4; j++) {
            if (!vis[nr + mv[j][0]][nc + mv[j][1]]) freeNeighbors++;
        }
        if (freeNeighbors == 0) { vis[r][c] = false; return 0; }
    }

    // turn already determined
    if (p[idx] < 4) {
        int nextR = r + mv[p[idx]][0];
        int nextC = c + mv[p[idx]][1];

        if (!vis[nextR][nextC]) {
            ret += tryPath(idx+1, nextR, nextC);
        }
    } else {
        // turn not determined - iterate through all 4 possibilities
        for (int i = 0; i < 4; i++) {
            int nextR = r + mv[i][0];
            int nextC = c + mv[i][1];

            if (!vis[nextR][nextC]) {
                ret += tryPath(idx+1, nextR, nextC);
            }
        }
    }

    vis[r][c] = false;
    return ret;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    for (int i = 0; i < 49; i++) p[i] = 4;

    // convert path to integers, 4 if ?
    for (int i = 0; i < 48; i++) {
        switch (s[i]) {
            case 'U': p[i] = 0; break;
            case 'R': p[i] = 1; break;
            case 'D': p[i] = 2; break;
            case 'L': p[i] = 3; break;
            default: break;
        }
    }

    // 9x9 grid: border is true (wall), interior 1-7 is false (unvisited)
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            vis[i][j] = (i == 0 || i == 8 || j == 0 || j == 8);

    cout << tryPath(0, 1, 1) << endl;
    return 0;
}
