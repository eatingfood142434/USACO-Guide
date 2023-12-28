#include <bits/stdc++.h>
using namespace std;

const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m, amt, amt_g;
    cin >> t;
    while (t--) {
        amt = 0, amt_g = 0;
        cin >> n >> m;
        char grid[n][m];
        bool visited[n][m];
        memset(visited, false, n*m);
        for (auto& a: grid) for (char& b: a) {cin >> b; if (b == 'G') amt_g++;}
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 'B') {
                    for (int i = 0; i < 4; i++) {
                        if (r+R_CHANGE[i] < 0 || r+R_CHANGE[i] >= n || c+C_CHANGE[i] < 0 || c+C_CHANGE[i] >= m || grid[r+R_CHANGE[i]][c+C_CHANGE[i]] != '.') continue;
                        grid[r+R_CHANGE[i]][c+C_CHANGE[i]] = '#';
                    }
                }
            }
        }
        
        bool pass = true;
        stack<pair<int,int>> frontier;
        frontier.push({n-1,m-1});
        while (!frontier.empty()) {
            int r1 = frontier.top().first;
            int c1 = frontier.top().second;
            frontier.pop();
            if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m || grid[r1][c1] == '#' || visited[r1][c1]) continue;
            if (grid[r1][c1] == 'G') amt++;
            else if (grid[r1][c1] == 'B') pass = false;
            visited[r1][c1] = true;
            for (int i = 0; i < 4; i++) frontier.push({r1+R_CHANGE[i], c1+C_CHANGE[i]});
        }
        cout << ((amt==amt_g && pass)?"Yes\n":"No\n");
    }

    return 0;
}