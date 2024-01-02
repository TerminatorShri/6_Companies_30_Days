#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        map<string, vector<int>> mp;
        for (int i = 0; i < access_times.size(); i++)
        {
            // Save name of employee as a key and their access times as values in vector
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        vector<string> ans;
        for (auto &it : mp)
            sort(it.second.begin(), it.second.end()); // Sort access times for each employee
        for (auto it : mp)
        {
            vector<int> temp = it.second;
            for (int i = 2; i < temp.size(); i++)
            {
                // If for any employee difference between curr and curr + 2 aceess times is less than 100 means he has accessed at least thrice in 1 hr
                if (temp[i] - temp[i - 2] < 100)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    return 0;
}