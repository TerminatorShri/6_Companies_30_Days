#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
            {
                temp.push_back(nums[j]);
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k)
                {
                    st.insert(temp);
                }
                else
                {
                    break;
                }
            }
        }
        return st.size();
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
    int k, p;
    cin >> k >> p;
    Solution obj;
    int ans = obj.countDistinct(nums, k, p);
    cout << ans << "\n";
    return 0;
}