#include <bits/stdc++.h>
using namespace std;

const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, amt = 0;
    cin >> n >> m;
    char grid[n][m];
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    for (auto& a: grid) for (char& b: a) cin >> b;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (visited[r][c] || grid[r][c] == '#') continue;
            stack<pair<int,int>> frontier;
            frontier.push({r,c});
            while (!frontier.empty()) {
                int r1 = frontier.top().first;
                int c1 = frontier.top().second;
                frontier.pop();
                if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m || grid[r1][c1] == '#' || visited[r1][c1]) continue;
                visited[r1][c1] = true;
                for (int i = 0; i < 4; i++) frontier.push({r1+R_CHANGE[i], c1+C_CHANGE[i]});
            }
            amt++;
        }
    }
    cout << amt;

    return 0;
}