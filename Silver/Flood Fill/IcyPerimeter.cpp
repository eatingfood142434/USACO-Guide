#include <bits/stdc++.h>
using namespace std;

const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    int n, a, p;
    cin >> n;
    char grid[n][n];
    bool visited[n][n];
    pair<int,int> ret = {0,0};
    memset(visited, false, n*n);
    for (auto& a: grid) for (char& b: a) cin >> b;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (visited[r][c] || grid[r][c] == '.') continue;
            a = 0; p = 0;
            stack<pair<int,int>> frontier;
            frontier.push({r,c});
            while (!frontier.empty()) {
                int r1 = frontier.top().first;
                int c1 = frontier.top().second;
                frontier.pop();
                if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= n || grid[r1][c1] == '.') {
                    p++;
                    continue;
                }
                if (visited[r1][c1]) continue;
                a++;
                visited[r1][c1] = true;
                for (int i = 0; i < 4; i++) frontier.push({r1+R_CHANGE[i], c1+C_CHANGE[i]});
            }
            if (a > ret.first || (a == ret.first && p < ret.second)) ret = {a,p};
        }
    }
    cout << ret.first << " " << ret.second;

    return 0;
}