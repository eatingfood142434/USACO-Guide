#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
typedef long long ll;

int dist(const pair<int,int>& a, const pair<int,int>& b) {
	int x = (a.first-b.first);
	int y = (a.second-b.second);
	return x*x+y*y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    map<char,pair<int,int>> dir = {{'N',{0,1}},{'E',{1,0}},{'S',{0,-1}},{'W',{-1,0}}};
    int n, m;
    pair<int,int> f, b;
    string fp, bp;
    cin >> n >> m >> f.a >> f.b >> b.a >> b.b >> fp >> bp;
    int s1 = fp.size(), s2 = bp.size();
    
    pair<int,int> psa_f[s1+1], psa_b[s2+1];
    psa_f[0] = f, psa_b[0] = b;
    for (int i = 1; i <= s1; i++) psa_f[i] = {psa_f[i-1].a+dir[fp[i-1]].a, psa_f[i-1].b+dir[fp[i-1]].b};
    for (int i = 1; i <= s2; i++) psa_b[i] = {psa_b[i-1].a+dir[bp[i-1]].a, psa_b[i-1].b+dir[bp[i-1]].b};
    
    vector<vector<ll>> dp(s1+1, vector<ll>(s2+1, 1e18));
    dp[0][0] = 0;
    for (int r = 0; r <= s1; r++) {
        for (int c = 0; c <= s2; c++) {
            if (r > 0) dp[r][c] = min(dp[r][c], dp[r-1][c]+dist(psa_f[r], psa_b[c]));
            if (c > 0) dp[r][c] = min(dp[r][c], dp[r][c-1]+dist(psa_f[r], psa_b[c]));
            if (r > 0 && c > 0) dp[r][c] = min(dp[r][c], dp[r-1][c-1]+dist(psa_f[r], psa_b[c]));
        }
    }
    cout << dp[s1][s2];
    
    return 0;
}