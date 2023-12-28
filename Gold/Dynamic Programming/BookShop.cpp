#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int price[n], pages[n];
    for (int& i: price) cin >> i;
    for (int& i: pages) cin >> i;
    ll dp[x+1] = {}; dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (dp[j] > 0 && j+price[i] <= x) dp[j+price[i]] = max(dp[j]+pages[i], dp[j+price[i]]);
        }
    }
    cout << *max_element(dp,dp+x+1)-1;
    
    return 0;
}