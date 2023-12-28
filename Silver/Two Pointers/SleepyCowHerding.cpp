#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int n;
    cin >> n;
    int cows[n], diffs[n-1];
    for (int& i: cows) cin >> i;
    sort(cows, cows+n);
    
    if ((cows[n-1]-cows[1] == n-2 && cows[1]-cows[0] > 2) ||
        (cows[n-2]-cows[0] == n-2 && cows[n-1]-cows[n-2] > 2)) cout << 2 << "\n";
    else {
        int h = 0, amt = INT_MAX;
        for (int i = 0; i < n; i++) {
            while (h+1 < n && cows[h+1] - cows[i] < n) h++;
            amt = min(amt, n-(h-i+1));
        }
        cout << amt << "\n";
    }
    
    int gap_num = 0;
	for (int i = 1; i < n; i++) gap_num += cows[i]-cows[i-1]-1;
	cout << max(gap_num-(cows[1]-cows[0]-1), gap_num-(cows[n-1]-cows[n-2]-1));

    return 0;
}