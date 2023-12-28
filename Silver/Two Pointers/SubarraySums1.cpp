#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int nums[n];
    for (int& i: nums) cin >> i;
    int ret = 0, sub_sum = 0, lower = 0, upper = 0;
    while (upper < n) {
        sub_sum += nums[upper]; upper++;
        while (sub_sum > x) {sub_sum -= nums[lower]; lower++;}
        if (sub_sum == x) ret++;
    }
    cout << ret;
    
    return 0;
}