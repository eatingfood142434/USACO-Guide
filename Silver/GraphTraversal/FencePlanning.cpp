#include <bits/stdc++.h>
using namespace std;

pair<int,int> coords[100000];
vector<int> adj[100000];
bool visited[100000];
int xmax, xmin, ymax, ymin;

void dfs(int k) {
    
    if (!visited[k]) {
        visited[k] = true;
        xmax = max(xmax, coords[k].first);
        xmin = min(xmin, coords[k].first);
        ymax = max(ymax, coords[k].second);
        ymin = min(ymin, coords[k].second);
        for (const int& i: adj[k]) dfs(i);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    int n, m, ret = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> coords[i].first >> coords[i].second;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            xmax = 0; xmin = INT_MAX; ymax = 0; ymin = INT_MAX;
            dfs(i);
            ret = min(ret, 2*(xmax-xmin+ymax-ymin));
        }
    }
    cout << ret;
    
    return 0;
}