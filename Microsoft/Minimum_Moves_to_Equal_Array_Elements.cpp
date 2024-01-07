#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int sz = nums.size(), ans = 0;
        sort(nums.begin(), nums.end()); // Sort array
        int median = nums[sz / 2];      // Find median
        for (int i = 0; i < sz; i++)
        {
            ans += abs(nums[i] - median); // Calculate absolute difference and add to count
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.minMoves2(nums) << "\n";
    return 0;
}