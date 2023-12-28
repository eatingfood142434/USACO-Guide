#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    int n;
    cin >> n;
    vector<int> cows[n];
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        cows[i] = {i,a,b};
    }
    sort(cows, cows+n, [](const vector<int> &a, const vector<int> &b) {return a[1] < b[1];});
    
    set<vector<int>> waiting;
    int curr = 0, cur_time = 0, max_wait = 0;
    while (curr < n || !waiting.empty()) {
        if (curr < n && cows[curr][1] <= cur_time) {
            waiting.insert(cows[curr]);
            curr++;
        }
        else if (waiting.empty()) {
            cur_time = cows[curr][1] + cows[curr][2];
            curr++;
        }
        else {
            max_wait = max(max_wait, cur_time-(*waiting.begin())[1]);
            cur_time += (*waiting.begin())[2];
            waiting.erase(waiting.begin());
        }
    }
    cout << max_wait;
    
    return 0;
}