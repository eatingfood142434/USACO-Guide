#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> grass(m);
    for (pair<ll,ll>& i: grass) cin >> i.first >> i.second;
    sort(grass.begin(), grass.end());
    ll l = 0, h = grass[m-1].second-grass[0].first, mid, amt, last, max_dist = 0;
    while (h-l > 1) {
        mid = (h+l)/2;
        amt = 0; last = -mid;
        for (pair<ll,ll>& i: grass) {
            if (i.first-last < mid) {
                if (last+mid > i.second) continue;
                last += mid;
            }
            else last = i.first;
            amt += (i.second-last)/mid+1;
        }
        if (amt >= n) {
            max_dist = max(max_dist, mid);
            l = mid;
        }
        else h = mid;
    }
    cout << max_dist;
    
    return 0;
}