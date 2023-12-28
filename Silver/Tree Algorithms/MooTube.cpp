#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[5000];
bool visited[5000];
int relevance[5000];
int ret;

void dfs(int n, int k) {
    visited[n] = true;
    ret++;
    for (const pair<int,int>& i: adj[n]) if (!visited[i.first] && i.second >= k) dfs(i.first, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0, a, b, c; i < n-1; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    for (int i = 0, k, v; i < q; i++) {
        cin >> k >> v;
        ret = 0;
        memset(visited, false, sizeof(visited));
        dfs(v-1, k);
        cout << ret-1 << "\n";
    }
    
    return 0;
}