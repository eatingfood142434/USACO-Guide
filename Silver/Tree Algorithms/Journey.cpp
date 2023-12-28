#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000];
double ret;

void dfs(int n, int d, double p) {
    visited[n] = true;
    int moves = 0;
    for (const int& i: adj[n]) if (!visited[i]) moves++;
    if (!moves) {
        ret += d*p;
        return;
    }
    for (const int& i: adj[n]) {
        if (!visited[i]) {
            dfs(i, d+1, p/moves);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0,0,1);
    cout << fixed << ret;
    
    return 0;
}