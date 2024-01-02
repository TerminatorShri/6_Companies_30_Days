#include <bits/stdc++.h>
using namespace std;

/*
Platform => LeetCode
Difficulty => Medium
*/

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int curr)
    {
        if (k == 0) // If k and target has become zero store the combination
        {
            if (n == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = curr; i <= 9; i++) // Subtract current number from target i.e. add number to combination and make a recursive call fro next number
        {
            temp.push_back(i);
            solve(ans, temp, k - 1, n - i, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, k, n, 1);
        return ans;
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum3(k, n);
    for (auto it : ans)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}