#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int& i: b) cin >> i;
    sort(b.begin(), b.end());
    
    int l = 1, h = b[n-1], mid, lowest, amt, cur, ret = 1e9;
    while (h >= l) {
        mid = (h+l)/2;
        lowest = 0;
        amt = 0;
        for (int bar = 0; bar < k && amt < n; bar++) {
			cur = b[amt] +mid*2;
			while (amt < n-1 && b[amt+1] <= cur) amt++;
			amt++;
		}
        if (amt >= n) {
            ret = min(ret, mid);
            h = mid-1;
        }
        else l = mid+1;
    }
    cout << ret;
    
    return 0;
}