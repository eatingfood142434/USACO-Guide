#include <bits/stdc++.h>
using namespace std;

struct Range {int start, stop, amt;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n, k;
    cin >> n >> k;
    int diamonds[n];
    for (int& i: diamonds) cin >> i;
    sort(diamonds, diamonds+n);
    vector<Range> diffs;
    
    int high = 0, max1 = 0, max2 = 0, amt1 = 0, temp;
    for (int i = 0; i < n && high < n; i++) {
        if (i == 0 || diamonds[i-1] != diamonds[i]) {
            for (int a = high; a < n; a++) {
                if (diamonds[a] > diamonds[i]+k) break;
                high++;
            }
            diffs.push_back({i, high-1, high-i});
        }
    }
    
    sort(diffs.begin(), diffs.end(), [](const Range& a, const Range& b){return a.amt > b.amt;});
    for (int a = 0; a < diffs.size(); a++) {
        for (int b = a+1; b < diffs.size(); b++) {
            if (diffs[a].stop < diffs[b].start || diffs[a].start > diffs[b].stop) {
                amt1 = max(amt1, diffs[a].amt+diffs[b].amt);
                break;
            }
        }
    }
    if (amt1 == 0) cout << n;
    else cout << amt1;
    
    return 0;
}