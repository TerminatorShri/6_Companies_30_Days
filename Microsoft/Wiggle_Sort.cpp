#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        priority_queue<int> pq;
        for (auto it : nums)
            pq.push(it);
        int i = 1, sz = nums.size();
        while (i < sz)
        {
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }
        i = 0;
        while (i < sz)
        {
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }
    }
};

int main()
{
    int sz;
    cin >> sz;
    vector<int> nums(sz);
    for (int i = 0; i < sz; i++)
        cin >> nums[i];
    Solution obj;
    obj.wiggleSort(nums);
    for (auto it : nums)
        cout << it << " ";
    return 0;
}