#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    pair<int,int> nums[n];
    for (int i = 0; i < n; i++) {cin >> nums[i].first; nums[i].second = i+1;}
    sort(nums, nums+n);
    int lower = 0, upper = n-1;
    while (lower != upper) {
        if (nums[lower].first+nums[upper].first == x) {cout << nums[lower].second << " " << nums[upper].second; return 0;}
        if (nums[lower].first+nums[upper].first < x) lower++;
        else upper--;
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}