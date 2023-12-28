#include <bits/stdc++.h>
using namespace std;

bool grid[4003][2003];
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    int n, ret = 0;
    char t;
    int r1 = 2001, c1 = 2001;
    int min_x = INT_MAX, max_x = 0, min_y = INT_MAX, max_y = 0;
    grid[r1][c1] = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        switch(t) {
            case 'N':
                r1--; grid[r1][c1] = true;
                r1--; grid[r1][c1] = true;
                break;
            case 'S':
                r1++; grid[r1][c1] = true;
                r1++; grid[r1][c1] = true;
                break;
            case 'E':
                c1++; grid[r1][c1] = true;
                c1++; grid[r1][c1] = true;
                break;
            case 'W':
                c1--; grid[r1][c1] = true;
                c1--; grid[r1][c1] = true;
                break;
        }
        min_x = min(min_x, r1);
        max_x = max(max_x, r1);
        min_y = min(min_y, c1);
        max_y = max(max_y, c1);
    }
    
    for (int r = min_x-1; r <= max_x+1; r++) {
        for (int c = min_y-1; c <= max_y+1; c++) {
            if (!grid[r][c]) {
                stack<pair<int,int>> frontier;
                frontier.push({r,c});
                while (!frontier.empty()) {
                    r1 = frontier.top().first;
                    c1 = frontier.top().second;
                    frontier.pop();
                    if (r1 < min_x-1 || r1 > max_x+1 || c1 < min_y-1 || c1 > max_y+1 || grid[r1][c1]) continue;
                    grid[r1][c1] = true;
                    for (int i = 0; i < 4; i++) frontier.push({r1+R_CHANGE[i],c1+C_CHANGE[i]});
                }
                ret++;
            }
        }
    }
    cout << ret-1;
    
    return 0;
}