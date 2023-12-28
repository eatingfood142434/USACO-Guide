#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000];

void dfs(int n) {
    if (!visited[n]) {
        visited[n] = true;
        for (const int& i: adj[n]) dfs(i);
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
    
    dfs(0);
    vector<pair<int,int>> newroads;
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            newroads.push_back({1,i+1});
            dfs(i);
        }
    }
    cout << newroads.size() << "\n";
    for (const pair<int,int>& i: newroads) cout << i.first << " " << i.second << "\n";
    
    return 0;
}