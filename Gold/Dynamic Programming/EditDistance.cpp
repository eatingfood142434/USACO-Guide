#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, INT_MAX));
    dp[0][0] = 0;
    for (int r = 0; r <= s1.size(); r++) {
        for (int c = 0; c <= s2.size(); c++) {
            if (r > 0) dp[r][c] = min(dp[r][c], dp[r-1][c]+1);
            if (c > 0) dp[r][c] = min(dp[r][c], dp[r][c-1]+1);
            if (r > 0 && c > 0) dp[r][c] = min(dp[r][c], dp[r-1][c-1] + (s1[r-1]!=s2[c-1]));
        }
    }
    cout << dp[s1.size()][s2.size()];
    
    return 0;
}