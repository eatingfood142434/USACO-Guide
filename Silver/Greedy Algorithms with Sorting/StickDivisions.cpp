#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    long long ret = 0;
    for (int i = 1, a, b; i < n; i++) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a+b);
        ret += a+b;
    }
    cout << ret;
    
    return 0;
}