#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
pair<int,int> maxleaf;

void dfs(int n, int e, int d) {
    int amt = 0;
    for (const int& i: adj[n]) if (i != e) dfs(i,n,d+1);
    if (d > maxleaf.second) maxleaf = {n,d};
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
    dfs(0,-1,0);
    dfs(maxleaf.first,-1,0);
    cout << maxleaf.second;
    
    return 0;
}