#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<map<int,int>> max_size(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_size[i][a[i]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (auto& [gcd, size]: max_size[i-1]) {
                int new_gcd = __gcd(gcd, a[i]);
                max_size[i][new_gcd] = max(max_size[i][new_gcd], size+1);
            }
        }
        
        vector<int> ans(n+1);
        for (int i = 0; i < n; i++) {
            for (auto& [gcd, size]: max_size[i]) {
                ans[size] = max(ans[size], gcd);
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    
	return 0;
}