#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int& i: arr) cin >> i;
    long long prefix_sum = 0, ret = 0;
    map<long long,int> sums; sums[0] = 1;
    for (const int& i: arr) {
        prefix_sum += i;
        ret += sums[prefix_sum-x];
        sums[prefix_sum]++;
    }
    cout << ret;
    return 0;
}