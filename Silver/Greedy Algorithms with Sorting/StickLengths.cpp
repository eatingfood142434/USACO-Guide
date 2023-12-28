#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for (int& i: s) cin >> i;
    sort(s.begin(), s.end());
    int med = s[n/2];
    long long ret = 0;
    for (const int& i: s) ret += abs(i-med);
    cout << ret;
    
    return 0;
}