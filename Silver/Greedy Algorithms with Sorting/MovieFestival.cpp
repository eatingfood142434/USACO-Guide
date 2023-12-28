#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h = 0, amt = 0;
    cin >> n;
    pair<int,int> m[n];
    for (pair<int,int>& i: m) cin >> i.first >> i.second;
    sort(m, m+n, [](const pair<int,int>& a, const pair<int,int>& b){return a.second < b.second;});
    for (const pair<int,int>& i: m) {
        if (i.first >= h) {
            h = i.second;
            amt++;
        }
    }
    cout << amt;
    
    return 0;
}