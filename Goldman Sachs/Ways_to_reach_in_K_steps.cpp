#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(vector<vector<int>> &dp, int src, int dest, int k)
    {
        if (k == 0)
        {
            if (src == dest)
                return 1;
            else
                return 0;
        }
        if (dp[src][k] != -1)
            return dp[src][k] % mod;
        // Make a recursive call by incrementing and decrementing src and k simultaneously
        return dp[src][k] = (solve(dp, src + 1, dest, k - 1) % mod + solve(dp, src - 1, dest, k - 1) % mod) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        if (abs(startPos - endPos) % 2 != k % 2)
            return 0;
        vector<vector<int>> dp(3003, vector<int>(1001, -1));
        return solve(dp, startPos + k, endPos + k, k);
    }
};

int main()
{
    int start, end, k;
    cin >> start >> end >> k;
    Solution obj;
    cout << obj.numberOfWays(start, end, k) << "\n";
    return 0;
}