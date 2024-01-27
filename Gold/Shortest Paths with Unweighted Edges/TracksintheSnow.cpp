#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int h, w, ret = 1;
char tracks[4000][4000];
int depth[4000][4000];

bool inside(int x, int y) {
	return (x > -1 && x < h && y > -1 && y < w && tracks[x][y] != '.');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> h >> w;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            cin >> tracks[r][c];
        }
    }
    
    deque<pair<int,int>> q;
    depth[0][0] = 1;
    q.push_back({0,0});
    while (!q.empty()) {
        pair<int,int> c = q.front();
        q.pop_front();
        ret = max(ret, depth[c.first][c.second]);
        
        for (int i = 0; i < 4; i++) {
            int x = c.first + dx[i], y = c.second + dy[i];
            if (inside(x, y) && depth[x][y] == 0) {
                if (tracks[c.first][c.second] == tracks[x][y]) {
                    depth[x][y] = depth[c.first][c.second];
                    q.push_front({x,y});
                }
                else {
                    depth[x][y] = depth[c.first][c.second] + 1;
                    q.push_back({x,y});
                }
            }
        }
    }
    cout << ret;
    
    return 0;
}