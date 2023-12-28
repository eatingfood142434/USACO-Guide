#include <bits/stdc++.h>
using namespace std;

struct Cow {int x, y, power;};

Cow cows[200];
int dists[200][200] = {};
bool visited[200];
int n, amt;

void dfs(int k) {
    if (!visited[k]) {
        visited[k] = true;
        amt++;
        for (int i = 0; i < n; i++) {
            if (dists[i][k] <= cows[k].power) dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cows[i].x >> cows[i].y >> cows[i].power;
    
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b || dists[a][b] != 0) continue;
            int d = ceil(sqrt((cows[a].x-cows[b].x)*(cows[a].x-cows[b].x)+(cows[a].y-cows[b].y)*(cows[a].y-cows[b].y)));
            dists[a][b] = d;
            dists[b][a] = d;
        }
    }
    
    int ret = 0;
    for (int i = 0; i < n; i++) {
        amt = 0;
        memset(visited,0,sizeof(visited));
        dfs(i);
        ret = max(ret, amt);
    }
    cout << ret;
    
    return 0;
}