#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n;
    cin >> n;
    pair<int,int> nums[n];
    for (auto& i: nums) cin >> i.first >> i.second;
    sort(nums, nums+n, [](pair<int,int> a, pair<int,int> b){return a.second < b.second;});
    int lower = 0, upper = n-1, ret = 0, amtcows;
    while (lower != upper) {
        amtcows = min(nums[lower].first, nums[upper].first);
        ret = max(ret, nums[lower].second+nums[upper].second);
        nums[lower].first -= amtcows; nums[upper].first -= amtcows;
        if (nums[lower].first == 0) lower++;
        if (nums[upper].first == 0) upper--;
    }
    cout << ret;
    
    return 0;
}