#include <bits/stdc++.h>
using namespace std;

int adj[100000], amt[100000], in_degree[100000];
bool departed[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> adj[i] >> amt[i];
        adj[i]--;
        in_degree[adj[i]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) if (in_degree[i] == 0) q.push(i);
    
    long long ret = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ret += amt[x];
        in_degree[adj[x]]--;
        departed[x] = true;
        if (in_degree[adj[x]] == 0) q.push(adj[x]);
    }
    
    for (int i = 0; i < n; i++) {
        if (!departed[i]) {
            int curr = i, start = i, min_moo = amt[i];
            do {
                ret += amt[curr];
                min_moo = min(min_moo, amt[curr]);
                departed[curr] = true;
                curr = adj[curr];
            } while (curr != start);
            ret -= min_moo;
        }
    }
    cout << ret;
    
    return 0;
}