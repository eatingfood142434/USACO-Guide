#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    vector<vector<int>> diff(n, vector<int>(n,0));
 
    int curr = 0;
    for (int i = 0; i < n; i++) curr += (a[i] == b[i]);
    
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            // suppose you swap a[i] and b[j];
            if (a[i] == b[i]) diff[i][j]--;
            if (a[j] == b[j]) diff[i][j]--;
            if (a[i] == b[j]) diff[i][j]++;
            if (a[j] == b[i]) diff[i][j]++;
            if (i+1 <= j-1) diff[i][j] += diff[i+1][j-1];
        }
    }


    vector<int> ret(n+1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ret[curr+diff[i][j]]++;
            // cout << i << ',' << j << ": " << diff[i][j] << "\n";
        }
    }

    for (const int& i: ret) cout << i << "\n";
    return 0;
}