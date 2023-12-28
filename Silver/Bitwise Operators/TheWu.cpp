#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    string s;
    cin >> n >> m >> q;
    int w[n];
    for (int& i: w) cin >> i;
    map<int,int> cnt;
    for (int i = 0; i < m; i++) {
        cin >> s;
        cnt[stoi(s, nullptr, 2)]++;
    }
    
    // Precompute Wu values
    vector<int> wu(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) wu[i] += w[n-j-1];
		}
	}
    
    int ans[(1<<n)][101] = {};
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < (1<<n); j++) {
            int mask = (1 << n)-1;
            int diff = i^j;
            if (wu[~diff&mask] <= 100) ans[i][wu[~diff&mask]] += cnt[j];
        }
        for(int j = 0; j < 100; j++) ans[i][j+1] += ans[i][j];
    }
    
    int k;
    while (q--) {
        cin >> s >> k;
        cout << ans[stoi(s, nullptr, 2)][k] << "\n";
    }
    
    return 0;
}