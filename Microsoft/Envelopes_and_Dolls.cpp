#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Hard
*/

class Solution
{
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int solve(vector<vector<int>> envelopes)
    {
        // Find length of LIS considering only height using binary search
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++)
        {
            if (envelopes[i][1] > ans.back())
            {
                ans.push_back(envelopes[i][1]);
            }
            else
            {
                int indx = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[indx] = envelopes[i][1];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // Sort envelopes in increasing order of width and if width in same then decreasing order of height
        sort(envelopes.begin(), envelopes.end(), comparator);
        return solve(envelopes);
    }
};

int main()
{
    int num;
    cin >> num;
    vector<vector<int>> envelopes(num, vector<int>(2));
    for (int i = 0; i < num; i++)
    {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }
    Solution obj;
    int ans = obj.maxEnvelopes(envelopes);
    cout << ans << "\n";
    return 0;
}