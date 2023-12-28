#include <bits/stdc++.h>
using namespace std;

vector<int> tp, ans;
vector<bool> visited;
queue<int> path;
int steps;

void dfs(int n) {
    path.push(n);
    if (visited[n]) {
        steps += ans[n];
        return;
    }
    visited[n] = true;
    steps++;
    dfs(tp[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, dcr;
    cin >> n;
    
    tp = vector<int>(n);
    ans = vector<int>(n,0);
    visited = vector<bool>(n,false);
    for (int& i: tp) {cin >> i; i--;}
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            steps = 0;
            dfs(i);
            dcr = 1;
            while (!path.empty()) {
                if (path.front() == path.back()) dcr = 0;
                ans[path.front()] = steps;
                steps -= dcr;
                path.pop();
            }
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    
    return 0;
}