#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
    if (n == 4) return {2,4,1,3};
    vector<int> prev = solve(n-1);
    for (const int& i: prev) cout << i << " ";
    cout << "\n";
    int c = n-1;
    while (abs(prev[c-1]-n) <= 1 || (c <= n-2 && abs(prev[c]-n) <= 1)) c--;
    prev.insert(prev.begin()+c, n);
    cout << c << "\n";
    for (int i = c; i < n-2; i++) {
        if (prev[i+2] < prev[i+1] && abs(prev[i]-prev[i+2]) > 1) swap(prev[i+2],prev[i+1]);
    }
    return prev;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    vector<int> ret = solve(n);
    for (const int& i: ret) cout << i << " ";
    return 0;
}