#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3000];
bool visited[3000];
set<int> open;
int amt;

void dfs(int n) {
    if (!visited[n] && open.count(n)) {
        visited[n] = true;
        amt++;
        for (const int& i: adj[n]) {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    int n, m, a;
    cin >> n >> m;
    for (int i = 0, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) open.insert(i);
    
    amt = 0;
    dfs(0);
    if (amt == n) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
    while (n > 1) {
        n--;
        cin >> a;
        open.erase(a-1);
        memset(visited,0,sizeof(visited));
        amt = 0;
        dfs(*open.begin());
        if (amt == n) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        // for (const int& i: open) cout << i << " ";
        // cout << "\n";
        // cout << "dfs(" << *open.begin() << ") " << amt << " " << n << "\n";
    }
    cin >> a;
    
    return 0;
}