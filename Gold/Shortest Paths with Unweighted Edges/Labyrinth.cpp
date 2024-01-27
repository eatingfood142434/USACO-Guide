#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int n, m;
char maze[1000][1000];
string path[1000][1000];
map<pair<int,int>,char> dir = {{{-1,0},'U'}, {{1,0},'D'}, {{0,-1},'L'}, {{0,1},'R'}};

bool inside(int x, int y) {
	return (x > -1 && x < n && y > -1 && y < m && maze[x][y] != '#');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    pair<int,int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') start = {i,j};
            else if (maze[i][j] == 'B') end = {i,j};
        }
    }
    
    queue<pair<int,int>> q;
    q.push(start);
    
    while (!q.empty()) {
        pair<int,int> c = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = c.first + dx[i], y = c.second + dy[i];
            if (inside(x,y) && path[x][y] == "") {
                path[x][y] = path[c.first][c.second] + dir[{dx[i],dy[i]}];
                q.push({x,y});
            }
        }
    }
    if (path[end.first][end.second].size() > 0) cout << "YES\n" << path[end.first][end.second].size() << "\n" << path[end.first][end.second];
    else cout << "NO";
    
    return 0;
}