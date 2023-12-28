#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b, temp, ret=INT_MAX;
    cin >> n >> k >> b;
    set<int> broken;
    for (int i = 0; i < b; i++) {cin >> temp; broken.insert(temp);}
    int psa[n+1]; psa[0] = 0;
    for (int i = 1; i < n+1; i++) psa[i] = psa[i-1] + !broken.count(i);
    for (int i = 0; i < n+1-k; i++) {
        ret = min(ret, k-psa[i+k]+psa[i]);
        if (ret <= 0) {cout << 0; return 0;}
    }
    cout << ret;
    
    return 0;
}