#include <bits/stdc++.h>
using namespace std;

/*
Platform = > Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto it : queries)
        {
            int k = it[0], trim = it[1];
            priority_queue<pair<string, int>> pq;
            for (int i = 0; i < nums.size(); i++)
            {
                string curr = nums[i];
                if (trim < curr.length())
                    curr = curr.substr(curr.length() - trim, trim); // Trim the reuqired string
                pair<string, int> p = {curr, i};
                if (pq.size() < k) // If size of priority queue is less than k insert the pair
                {
                    pq.push(p);
                }
                else
                {
                    // Else if it is equal to k insert only if curr < string at top
                    if (curr < pq.top().first)
                    {
                        pq.pop();
                        pq.push(p);
                    }
                }
            }
            ans.push_back(pq.top().second); // Store the index for query in answer
        }
        return ans;
    }
};

int main()
{
    int num;
    cin >> num;
    vector<string> nums(num);
    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }
    int query;
    cin >> query;
    vector<vector<int>> queries(query, vector<int>(2, 0));
    for (int i = 0; i < query; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> ans = obj.smallestTrimmedNumbers(nums, queries);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}