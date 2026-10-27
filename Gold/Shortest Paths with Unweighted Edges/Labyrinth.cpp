#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
const char dir[4]{'D','U','R','L'};
 
int n, m;
char maze[1000][1000];
int prevStep[1000][1000];
 
bool inside(int x, int y) {
	return (x > -1 && x < n && y > -1 && y < m && maze[x][y] != '#');
}
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
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
            if (inside(x,y) && prevStep[x][y] == 0) {
                prevStep[x][y] = i+1;
                q.push({x,y});
            }
        }
    }
    if (prevStep[end.first][end.second] > 0) {
        cout << "YES\n";
        string path = "";
        pair<int,int> cur = end;
        int temp;
        while (cur != start) {
            temp = prevStep[cur.first][cur.second]-1;
            path += dir[temp];
            cur = {cur.first - dx[temp], cur.second - dy[temp]};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path;
    }
    else cout << "NO";
    
    return 0;
}