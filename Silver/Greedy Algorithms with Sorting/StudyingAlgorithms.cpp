#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, c = 0;
    cin >> n >> x;
    int arr[n];
    for (int& i: arr) cin >> i;
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        x -= arr[i];
        if (x < 0) {cout << i; return 0;}
    }
    cout << n;
    
    return 0;
}