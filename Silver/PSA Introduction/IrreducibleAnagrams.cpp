#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int q, n, a, b;
    cin >> s >> q;
    n = s.size();
    int counts[n+1][26] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) counts[i][j] = counts[i-1][j];
        counts[i][(s[i]-'a')]++;
    }
    
    while (q--) {
        cin >> a >> b;
        int cnt = 0;
        for (int i = 0; i < 26; i++) cnt += (counts[a-1][i] < counts[b][i]);
        if (a == b || cnt >= 3 || s[a-1] != s[b-1]) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}