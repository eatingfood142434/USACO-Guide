#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin >> n;
    int shuffle[n], after_shuffle[n] = {};
    queue<int> no_cows;
    for (int& i: shuffle) {
        cin >> i; i--;
        after_shuffle[i]++;
    }
    
    int ret = n;
    for (int i = 0; i < n; i++) {
        if (after_shuffle[i] == 0) {
            no_cows.push(i);
            ret--;
        }
    }
    
    while (!no_cows.empty()) {
        int curr = no_cows.front();
        no_cows.pop();
        if (after_shuffle[shuffle[curr]] == 0) {
            no_cows.push(shuffle[curr]);
            ret--;
        }
    }
    cout << ret;

    return 0;
}
