#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> times(n);
    for (int& i: times) cin >> i;
    sort(times.begin(), times.end());
    int l = 0, h = times[n-1]-times[0], mid;
    int lcow, curr, bus;
    while (h > l) {
        mid = (h+l)/2;
        lcow = 0; curr = 0; bus = 0;
        while (curr < n) {
            if (curr == lcow) bus++;
            if (times[curr] - times[lcow] > mid) lcow = curr;
            else if (curr-lcow+1 == c) lcow = ++curr;
            else curr++;
        }
        if (bus <= m) h = mid;
        else l = mid+1;
    }
    cout << l;
    
    return 0;
}