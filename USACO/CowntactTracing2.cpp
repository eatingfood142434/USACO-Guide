#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ret = 0;
    string s;
    vector<int> clumps;
    cin >> n >> s;
    int minclump = INT_MAX, curr = 0, l = 0, h = n-1;
    bool t = false, reachedend = false;
    
    while (s[l] == '1' && l < n) {
        curr++;
        l++;
        t = true;
        if (l == n-1) reachedend = true;
    }
    if (t) {
        minclump = min(minclump, 2*curr-1);
        clumps.push_back(curr);
        curr = 0;
        t = false;
    }
    
    while (!reachedend && s[h] == '1' && h >= 0) {
        curr++;
        h--;
        t = true;
    }
    if (t) {
        minclump = min(minclump, 2*curr-1);
        clumps.push_back(curr);
        curr = 0;
    }
    
    for (int i = l; i < h+1; i++) {
        if (s[i] == '1') curr++;
        else if (curr > 0) {
            minclump = min(minclump, curr);
            clumps.push_back(curr);
            curr = 0;
        }
    }
    if (curr > 1) {
        minclump = min(minclump, curr);
        clumps.push_back(curr);
    }
    if (minclump == INT_MAX) {
        cout << 0;
        return 0;
    }
    if (minclump%2 == 0) minclump--;
    for (int& i: clumps) {
        ret += ceil((double)i/minclump);
    }
    cout << ret;

    return 0;
}