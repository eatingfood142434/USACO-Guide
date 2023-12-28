#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000];
string cows;
map<int,int> component;
int comp = 0;

void dfs(int n, char c) {
    visited[n] = true;
    component[n] = comp;
    for (const int& i: adj[n]) if (!visited[i] && cows[i] == c) dfs(i,c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n, m;
    char c;
    cin >> n >> m >> cows;
    for (int i = 0, a, b; i < n-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cows[i] == 'G') {
            dfs(i,'G');
            comp++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cows[i] == 'H') {
            dfs(i,'H');
            comp++;
        }
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b >> c;
        if (component[a-1] != component[b-1]) cout << 1;
        else if (cows[a-1] == c) cout << 1;
        else cout << 0;
    }
    
    return 0;
}