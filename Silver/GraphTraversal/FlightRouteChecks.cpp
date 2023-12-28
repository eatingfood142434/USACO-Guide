#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000][2];
bool visited[100000];
void dfs(int n, int k) {
    visited[n] = true;
    for (const int& i: adj[n][k]) if (!visited[i]) dfs(i,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1][0].push_back(b-1);
        adj[b-1][1].push_back(a-1);
    }
    dfs(0,0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n" << 1 << " " << i+1;
            return 0;
        }
    }
    memset(visited, false, sizeof(visited));
    dfs(0,1);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n" << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";

    return 0;
}