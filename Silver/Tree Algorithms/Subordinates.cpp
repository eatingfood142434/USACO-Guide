#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
int dp[200000];
void dfs(int s, int e) {
    dp[s] = 1;
    for (int& i: adj[s]) {
        if (i == e) continue;
        dfs(i, s);
        dp[s] += dp[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1, a; i < n; i++) {
        cin >> a;
        adj[a-1].push_back(i);
    }
    dfs(0,0);
    for (int i = 0; i < n; i++) cout << dp[i]-1 << " ";
    
    return 0;
}