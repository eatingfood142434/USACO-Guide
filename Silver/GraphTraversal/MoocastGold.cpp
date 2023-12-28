#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n, m = 0;
    cin >> n;
    pair<int,int> cows[n];
    vector<int> dists(n,INT_MAX-1); dists[0] = 0;
    for (pair<int,int>& i: cows) cin >> i.first >> i.second;
    
    for (int a = 0; a < n; a++) {
        int i = min_element(dists.begin(),dists.end())-dists.begin();
        m = max(m, dists[i]);
        dists[i] = INT_MAX;
        for (int b = 0; b < n; b++) {
            if (dists[b] != INT_MAX) {
                dists[b] = min(dists[b], (cows[i].first-cows[b].first)*(cows[i].first-cows[b].first)+(cows[i].second-cows[b].second)*(cows[i].second-cows[b].second));
            }
        }
    }
    cout << m;
    
    return 0;
}