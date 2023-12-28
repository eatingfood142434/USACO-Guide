#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b;
    map<int,int> stacks;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        stacks[a]++;
        stacks[b+1]--;
    }
    int c = 0;
    vector<int> bales(n);
    for (int i = 0; i < n; i++) {
        c+=stacks[i];
        bales[i] = c;
    }
    sort(bales.begin(), bales.end());
    cout << bales[n/2];
    
    return 0;
}