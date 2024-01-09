#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Easy
*/

class Solution
{
public:
    int check(vector<int> temp)
    {
        int sz = temp.size();
        for (int i = 1; i < sz; i++)
        {
            // If at any point array is not strictly increasing return false
            if (temp[i] <= temp[i - 1])
                return 0;
        }
        return 1;
    }
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int sz = nums.size(), ans = 0;
        for (int i = 0; i < sz; i++)
        {
            for (int j = i; j < sz; j++)
            {
                // Consider all elements except the elements in range of i and j
                // Then check if it is incremovable
                vector<int> temp;
                for (int k = 0; k < i; k++)
                {
                    temp.push_back(nums[k]);
                }
                for (int k = j + 1; k < sz; k++)
                {
                    temp.push_back(nums[k]);
                }
                if (check(temp))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int num;
    cin >> num;
    vector<int> nums(num);
    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.incremovableSubarrayCount(nums) << "\n";
    return 0;
}