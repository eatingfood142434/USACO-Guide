#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[100000];
int dist[100000], parent[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    queue<int> q;
    dist[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (const int& i: adj[k]) {
            if (dist[i] == 0) {
                dist[i] = dist[k]+1;
                parent[i] = k;
                q.push(i);
            }
        }
    }
    
    if (dist[n-1] == 0) cout << "IMPOSSIBLE";
    else {
        int c = n-1;
        vector<int> path;
        while (c) {
            path.push_back(c);
            c = parent[c];
        }
        cout << dist[n-1] << "\n1 ";
        for (int i = path.size()-1; i >= 0; i--) cout << path[i]+1 << " ";
    }
    return 0;
}