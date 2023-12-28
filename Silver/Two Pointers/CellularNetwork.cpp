#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ret = 0;
    cin >> n >> m;
    int cities[n], towers[m];
    vector<int> dist(n, INT_MAX);
    for (int& i: cities) cin >> i;
    for (int& i: towers) cin >> i;
    int c = 0;
    for (int i = 0; i < n; i++) {
        while (c < (m-1) && towers[c+1] <= cities[i]) c++;
        dist[i] = min(dist[i], abs(cities[i]-towers[c]));
    }
    c = m-1;
    for (int i = n-1; i >= 0; i--) {
        while (c > 0 && towers[c-1] >= cities[i]) c--;
        dist[i] = min(dist[i], abs(cities[i]-towers[c]));
    }
    for (int& i: dist) ret = max(ret, i);
    cout << ret;
    
    return 0;
}