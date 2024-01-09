#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int solve(vector<int> nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pref_sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pref_sum += nums[i];
            if (mp.find(pref_sum - k) != mp.end())
            {
                ans += mp[pref_sum - k];
            }
            mp[pref_sum]++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // Convert odd number to one and even number to zero
        for (auto &it : nums)
        {
            if (it & 1)
                it = 1;
            else
                it = 0;
        }
        // Just use same logic that is used for finding number of sub-arrays having sum k
        return solve(nums, k);
    }
};

int main()
{
    int num, k;
    cin >> num >> k;
    vector<int> nums(num);
    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.numberOfSubarrays(nums, k) << "\n";
    return 0;
}