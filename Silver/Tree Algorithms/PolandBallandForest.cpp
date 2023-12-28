#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
bool visited[10000];

void dfs(int n) {
    visited[n] = true;
    for (const int& i: adj[n]) if (!visited[i]) dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ret = 0;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        adj[i].push_back(a-1);
        adj[a-1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            ret++;
        }
    }
    cout << ret;
    
    return 0;
}