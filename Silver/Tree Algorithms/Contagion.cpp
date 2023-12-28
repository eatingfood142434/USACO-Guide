#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
long long days;

void dfs(int n, int e) {
    int amt = 0;
    for (const int& i: adj[n]) {
        if (i != e) {
            amt++;
            dfs(i,n);
        }
    }
    days += amt;
    if (amt) days += ceil(log2(amt+1));
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
    dfs(0,0);
    cout << days;
    
    return 0;
}