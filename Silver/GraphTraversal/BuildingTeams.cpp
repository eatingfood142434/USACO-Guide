#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
vector<int> teams(100000);
bool impossible = false;

void dfs(int n, int x) {
    if (teams[n] == 0) {
        teams[n] = x;
        for (const int& i: adj[n]) {
            if (teams[i] == x) {
                impossible = true;
                return;
            }
            dfs(i, (x == 1) ? 2:1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (teams[i] == 0) {
            dfs(i, 1);
            if (impossible) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << teams[i] << " ";
    
    return 0;
}