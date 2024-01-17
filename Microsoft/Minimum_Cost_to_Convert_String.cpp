#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
    // Use Floyd Warshall Algorithm to find minimum possible cost from each char to every other char
    void floyd_warshall(vector<char> &original, vector<char> &changed,
                        vector<int> &cost, vector<vector<int>> &d)
    {
        int sz = original.size();
        for (int i = 0; i < sz; i++)
        {
            int r = original[i] - 'a';
            int c = changed[i] - 'a';
            d[r][c] = min(d[r][c], cost[i]);
        }
        for (int i = 0; i < 26; i++)
        {
            d[i][i] = 0;
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    d[i][j] =
                        min((long long)d[i][j], (long long)d[i][k] + d[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        vector<vector<int>> d(26, vector<int>(26, INT_MAX));
        floyd_warshall(original, changed, cost, d);
        long long ans = 0, len = source.length();
        for (int i = 0; i < len; i++)
        {
            int r = source[i] - 'a';
            int c = target[i] - 'a';
            // If not possible to convert curr char into a specfic char then return -1
            if (d[r][c] == INT_MAX)
                return -1;
            // Else add cost to ans
            ans += d[r][c];
        }
        return ans;
    }
};

int main()
{
    string src, target;
    cin >> src >> target;
    int cnt;
    vector<char> original(cnt), changed(cnt);
    vector<int> cost(cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin >> original[i] >> changed[i] >> cost[i];
    }
    Solution obj;
    int ans = obj.minimumCost(src, target, original, changed, cost);
    cout << ans << "\n";
    return 0;
}